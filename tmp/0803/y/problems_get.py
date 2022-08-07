#!/usr/bin/env python3
# coding: utf-8

from datetime import timedelta
import json

import requests
import requests_cache

requests_cache.install_cache('atcoder_problems', backend='sqlite', expire_after=timedelta(days=1))

def main(vcon_id):
    vcon_url = f'https://kenkoooo.com/atcoder/internal-api/contest/get/{vcon_id}'

    res = requests.get(vcon_url)
    # print(res.from_cache)
    data = json.loads(res.content)
    print(data)
    problems = sorted(data['problems'], key=lambda x: x['order'])

    print(f"""{data['info']['title']}
https://kenkoooo.com/atcoder/#/contest/show/{vcon_id}
""")
    for problem in problems:
        problem_id = problem['id']
        contest_id = problem['id'].rsplit('_', maxsplit=1)[0].replace('_', '-').lower()
        print(f"https://atcoder.jp/contests/{contest_id}/tasks/{problem_id}")

if __name__ == '__main__':
    # import fire
    # fire.Fire(main)

    # main('592f0a21-149d-4146-a4a1-d8fb32f9d397')
    main('974ab44a-4fac-40f1-9ab9-7a02fb27f999')
    # main('aafba7b1-3c1f-49c6-833b-a8f9431a00a2')
    # AtCoder Beginner of Beginner Contest 038 (Elementary)
    # https://kenkoooo.com/atcoder/#/contest/show/aafba7b1-3c1f-49c6-833b-a8f9431a00a2
    # 
    # https://atcoder.jp/contests/abc051/tasks/abc051_a
    # https://atcoder.jp/contests/abc061/tasks/abc061_b
    # https://atcoder.jp/contests/arc013/tasks/arc013_1
    # https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_b
    # https://atcoder.jp/contests/arc078/tasks/arc078_a
