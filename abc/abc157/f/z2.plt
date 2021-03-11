reset
set xrange [-180:-120]
set yrange [190:250]
set label 1 point pt 7 ps 1 at 128,553
set label 2 point pt 7 ps 1 at -656,-204
set label 3 point pt 7 ps 1 at -270,76
set parametric
plot [0:2*pi] 7411.2252/17 * cos(t) + 128, 7411.2252/17 * sin(t) + 553
replot [0:2*pi] 7411.2252/11 * cos(t) - 656, 7411.2252/11 * sin(t) - 204
replot [0:2*pi] 7411.2252/40 * cos(t) - 270, 7411.2252/40 * sin(t) + 76



