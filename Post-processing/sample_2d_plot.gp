set terminal svg enhanced background rgb 'white' size 1920, 1080 font 'Times, 50'
set border lw 4
set xtics font ',50'
set ytics font ',50'
set label font ',70'
set xlabel offset 0, 0.75
set ylabel offset 2.25, 0
set tics scale 0.5
set mxtics 4
set mytics 4
set xlabel '{/:Italic t}'

##position
set size ratio 1.25

##velocity
##set size ratio 0.75
##unset mytics
##range [-0.3:0.3]

##trajectory front view
set output ''                                                                     
set label 'Left-side wall' at -0.65, 3.5 rotate by 90                                                   
plot [-0.75:1.2][0:10]'case1 40.00/log' u 3:($4-4) w l t '{/:Italic Ga} = 40' lw 4 lc rgb 'red', \
'case6 62.00/log' u 3:($4-4) w l t '{/:Italic Ga} = 62' lw 4 lc rgb 'blue' dt 4, \                
'case9 90.5/log' u 3:($4-4) w l t '{/:Italic Ga} = 90.5' lw 4 lc rgb 'dark-green' dt 2 

##trajectory side view
set output ''
set label 'Rear Wall' at -0.65, 3.8 rotate by 90

plot [-0.75:1.2][0:10]'case1 40.00/log' u 5:($4-4) w l t '{/:Italic Ga} = 40' lw 4 lc rgb 'red', \
'case6 62.00/log' u 5:($4-4) w l t '{/:Italic Ga} = 62' lw 4 lc rgb 'blue' dt 4, \                
'case9 90.5/log' u 5:($4-4) w l t '{/:Italic Ga} = 90.5' lw 4 lc rgb 'dark-green' dt 2                                                                              
unset label

##wall-normal force                       
set output ''
set ylabel '{/:Italic F_x} \327 10^{-4}'
                               
plot [0:10][-1.5:1.5]'case1 40.00/fn10.txt' u 1:($2*1e4) w l t '{/:Italic Ga} = 40' lw 4 lc rgb 'dark-green' smooth bezier, \
'case6 62.00/fnx10.txt' u 1:($2*1e4) w l t '{/:Italic Ga} = 62' lw 4 lc rgb 'blue' dt 4 smooth bezier, \                     
'case9 90.5/fn10.txt' u 1:($9*1e4) w l t '{/:Italic Ga} = 90.5' lw 4 lc rgb 'red' dt 2 smooth bezier
                       
set output ''
set ylabel '{/:Italic F_z} \327 10^{-4}'                                                                                     
plot [0:10][-1.5:1.5]'case1 40.00/fn10.txt' u 1:($3*1e4) w l t '{/:Italic Ga} = 40' lw 4 lc rgb 'dark-green' smooth bezier, \  
'case6 62.00/fnz10.txt' u 1:($3*1e4) w l t '{/:Italic Ga} = 62' lw 4 lc rgb 'blue' dt 4 smooth bezier, \                     
'case9 90.5/fn10.txt' u 1:($10*1e4) w l t '{/:Italic Ga} = 90.5' lw 4 lc rgb 'red' dt 2 smooth bezier