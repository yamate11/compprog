#![allow(non_snake_case, unused_macros)]

use itertools::Itertools;
use proconio::input;
use rand::prelude::*;
use svg::node::{
    element::{Group, Rectangle, Title},
    Text,
};

pub trait SetMinMax {
    fn setmin(&mut self, v: Self) -> bool;
    fn setmax(&mut self, v: Self) -> bool;
}
impl<T> SetMinMax for T
where
    T: PartialOrd,
{
    fn setmin(&mut self, v: T) -> bool {
        *self > v && {
            *self = v;
            true
        }
    }
    fn setmax(&mut self, v: T) -> bool {
        *self < v && {
            *self = v;
            true
        }
    }
}

#[macro_export]
macro_rules! mat {
	($($e:expr),*) => { Vec::from(vec![$($e),*]) };
	($($e:expr,)*) => { Vec::from(vec![$($e),*]) };
	($e:expr; $d:expr) => { Vec::from(vec![$e; $d]) };
	($e:expr; $d:expr $(; $ds:expr)+) => { Vec::from(vec![mat![$e $(; $ds)*]; $d]) };
}

#[derive(Clone, Debug)]
pub struct Input {
    pub D: usize,
    pub c: Vec<i64>,
    pub s: Vec<Vec<i64>>,
}

impl std::fmt::Display for Input {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        writeln!(f, "{}", self.D)?;
        writeln!(f, "{}", self.c.iter().join(" "))?;
        for d in 0..self.D {
            writeln!(f, "{}", self.s[d].iter().join(" "))?;
        }
        Ok(())
    }
}

pub fn parse_input(f: &str) -> Input {
    let f = proconio::source::once::OnceSource::from(f);
    input! {
        from f,
        D: usize,
        c: [i64; 26],
        s: [[i64; 26]; D]
    }
    Input { D, c, s }
}

pub fn read<T: Copy + PartialOrd + std::fmt::Display + std::str::FromStr>(
    token: Option<&str>,
    lb: T,
    ub: T,
) -> Result<T, String> {
    if let Some(v) = token {
        if let Ok(v) = v.parse::<T>() {
            if v < lb || ub < v {
                Err(format!("Out of range: {}", v))
            } else {
                Ok(v)
            }
        } else {
            Err(format!("Parse error: {}", v))
        }
    } else {
        Err("Unexpected EOF".to_owned())
    }
}

pub struct Output {
    pub ts: Vec<usize>,
}

pub fn parse_output(input: &Input, f: &str) -> Result<Output, String> {
    let mut ts = vec![];
    let mut fs = f.lines();
    for _ in 0..input.D {
        ts.push(read(fs.next(), 1, 26)? - 1);
    }
    if fs.next().is_some() {
        return Err("Too many output".to_owned());
    }
    Ok(Output { ts })
}

pub fn gen(seed: u64) -> Input {
    let mut rng = rand_chacha::ChaCha20Rng::seed_from_u64(seed);
    let D = 365;
    let c = (0..26).map(|_| rng.gen_range(0..=100)).collect_vec();
    let mut s = mat![0; D; 26];
    for i in 0..D {
        for j in 0..26 {
            s[i][j] = rng.gen_range(0..=20000);
        }
    }
    Input { D, c, s }
}

fn compute_sat(input: &Input, out: &[usize]) -> (i64, (Vec<Vec<usize>>, Vec<Vec<i64>>)) {
    let mut sat = 0;
    let mut last = vec![0; 26];
    let mut lasts = vec![];
    let mut dsat = mat![0; out.len(); 26];
    for d in 0..out.len() {
        sat += input.s[d][out[d]];
        last[out[d]] = d + 1;
        lasts.push(last.clone());
        for i in 0..26 {
            dsat[d][i] = input.c[i] * (d + 1 - last[i]) as i64;
            sat -= dsat[d][i];
        }
    }
    (sat, (lasts, dsat))
}

pub fn compute_score(
    input: &Input,
    out: &[usize],
) -> (i64, String, (Vec<Vec<usize>>, Vec<Vec<i64>>)) {
    let (S, dsat) = compute_sat(input, out);
    ((1000000 + S).max(0), String::new(), dsat)
}

/// 0 <= val <= 1
pub fn color(mut val: f64) -> String {
    val.setmin(1.0);
    val.setmax(0.0);
    let (r, g, b) = if val < 0.5 {
        let x = val * 2.0;
        (
            30. * (1.0 - x) + 144. * x,
            144. * (1.0 - x) + 255. * x,
            255. * (1.0 - x) + 30. * x,
        )
    } else {
        let x = val * 2.0 - 1.0;
        (
            144. * (1.0 - x) + 255. * x,
            255. * (1.0 - x) + 30. * x,
            30. * (1.0 - x) + 70. * x,
        )
    };
    format!(
        "#{:02x}{:02x}{:02x}",
        r.round() as i32,
        g.round() as i32,
        b.round() as i32
    )
}

pub fn rect(x: usize, y: usize, w: usize, h: usize, fill: &str) -> Rectangle {
    Rectangle::new()
        .set("x", x)
        .set("y", y)
        .set("width", w)
        .set("height", h)
        .set("fill", fill)
}

pub fn vis_default(input: &Input, out: &[usize]) -> (i64, String, String) {
    vis(input, out, true, 0, 365)
}

pub fn vis(
    input: &Input,
    out: &[usize],
    show_number: bool,
    color_type: i32,
    max_turn: usize,
) -> (i64, String, String) {
    let max_turn = max_turn.min(input.D);
    let W = 30;
    let H = 12;
    let (score, err, (last, dsat)) = compute_score(input, out);
    let mut doc = svg::Document::new()
        .set("id", "vis")
        .set("viewBox", (-5, -5, W * 27 + 10, H * (max_turn + 3) + 10))
        .set("width", W * 27 + 10)
        .set("height", H * (max_turn + 3) + 10)
        .set("style", "background-color:white");
    doc = doc.add(
        svg::node::element::Text::new()
            .set("x", W / 2)
            .set("y", H * (max_turn + 2) + 9)
            .set("text-anchor", "middle")
            .set("font-size", 8)
            .add(Text::new("c[i]".to_string())),
    );
    for i in 0..26 {
        doc = doc.add(
            svg::node::element::Text::new()
                .set("x", W * (i + 1) + W / 2)
                .set("y", 9)
                .set("text-anchor", "middle")
                .set("font-size", 8)
                .add(Text::new((i + 1).to_string())),
        );
        doc = doc.add(rect(
            W * (i + 1),
            H * (max_turn + 2),
            W,
            H,
            &color(input.c[i] as f64 / 100.0),
        ));
        doc = doc.add(
            svg::node::element::Text::new()
                .set("x", W * (i + 1) + W / 2)
                .set("y", 9 + H * (max_turn + 2))
                .set("text-anchor", "middle")
                .set("font-size", 8)
                .add(Text::new(input.c[i].to_string())),
        );
    }
    let d0 = if out.len() < max_turn {
        0
    } else {
        out.len() - max_turn
    };
    for p in 0..max_turn {
        let d = d0 + p;
        doc = doc.add(
            svg::node::element::Text::new()
                .set("x", W / 2)
                .set("y", 9 + H * (max_turn - p))
                .set("text-anchor", "middle")
                .set("font-size", 8)
                .add(Text::new((d + 1).to_string())),
        );
        if d < out.len() {
            for i in 0..26 {
                doc = doc.add(
                    Group::new()
                        .add(Title::new().add(Text::new(format!(
                            "s[{}][{}] = {}\nc[{}] × ({} - {}) = {}",
                            d + 1,
                            i + 1,
                            input.s[d][i],
                            i + 1,
                            d + 1,
                            last[d][i],
                            dsat[d][i]
                        ))))
                        .add(rect(
                            W * (i + 1),
                            H * (max_turn - p),
                            W,
                            H,
                            &color(if color_type == 0 {
                                input.s[d][i] as f64 / 30000.0
                            } else {
                                dsat[d][i] as f64 / 3000.0
                            }),
                        )),
                );
                if show_number {
                    doc = doc.add(
                        svg::node::element::Text::new()
                            .set("x", W / 2 + W * (i + 1))
                            .set("y", 9 + H * (max_turn - p))
                            .set("text-anchor", "middle")
                            .set("font-size", 8)
                            .add(Text::new(
                                if color_type == 0 {
                                    input.s[d][i]
                                } else {
                                    dsat[d][i]
                                }
                                .to_string(),
                            )),
                    );
                }
            }
            doc = doc.add(
                rect(W * (out[d] + 1), H * (max_turn - p), W, H, "none")
                    .set("stroke", "black")
                    .set("stroke-width", 2),
            );
        }
    }
    (score, err, doc.to_string())
}
