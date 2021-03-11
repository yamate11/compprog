reset
set xrange [-1000:1000]
set yrange [-1000:1000]
set label 1 point pt 7 ps 1 at 128,553
set label 2 point pt 7 ps 1 at -656,-204
set label 3 point pt 7 ps 1 at -270,76
set parametric
plot [0:2*pi] 7411/17 * cos(t) + 128, 7411/17 * sin(t) + 553
replot [0:2*pi] 7411/11 * cos(t) - 656, 7411/11 * sin(t) - 204
replot [0:2*pi] 7411/40 * cos(t) - 270, 7411/40 * sin(t) + 76



