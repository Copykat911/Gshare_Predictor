clear
g++ Gshare.c -o Gshare
# Test cases
echo
echo "-- Gshare predictor simulator --"
echo "-- Computer Architecture --"
echo "-- Project 2 --"
echo "-- Michael Schumacher --"
echo
echo "	Simulator running, the please wait. . . the program should take 30 seconds to run"

1KB entries varying N		
echo "--------------- 1KB entries varying N ---------------" 		>> output.txt
echo "M	N	Miss %"		>> output.txt
./Gshare 10 0 mcf_trace.txt 					>> output.txt
echo "Loading . . . [1/11 trials finished]"
./Gshare 10 1 mcf_trace.txt 					>> output.txt
echo "Loading . . . [2/11 trials finished]"
./Gshare 10 2 mcf_trace.txt 					>> output.txt
echo "Loading . . . [3/11 trials finished]"
./Gshare 10 3 mcf_trace.txt 					>> output.txt
echo "Loading . . . [4/11 trials finished]"
./Gshare 10 4 mcf_trace.txt 					>> output.txt
echo "Loading . . . [5/11 trials finished]"
./Gshare 10 5 mcf_trace.txt 					>> output.txt
echo "Loading . . . [6/11 trials finished]"
./Gshare 10 6 mcf_trace.txt 					>> output.txt
echo "Loading . . . [7/11 trials finished]"
./Gshare 10 7 mcf_trace.txt 					>> output.txt
echo "Loading . . . [8/11 trials finished]"
./Gshare 10 8 mcf_trace.txt 					>> output.txt
echo "Loading . . . [9/11 trials finished]"
./Gshare 10 9 mcf_trace.txt 					>> output.txt
echo "Loading . . . [10/11 trials finished]"
./Gshare 10 10 mcf_trace.txt 					>> output.txt
echo "Loading . . . [11/11 trials finished]"

echo "-- END mcf_trace"						>> output.txt
echo "--------------- END 1KB entries varying N ---------------"	>> output.txt
echo
echo "Outputs for each trial have been logged in a single file, output.txt
	located in your current working directory"
echo