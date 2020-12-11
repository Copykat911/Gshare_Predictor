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
# 
# 
echo "--------------- Test cases ---------------" 	> output.txt
echo "M	N	Miss %"							>> output.txt
./Gshare 8 5 mcf_trace.txt 						>> output.txt
./Gshare 4 2 mcf_trace.txt 						>> output.txt
./Gshare 3 1 mcf_trace.txt 						>> output.txt
echo -- END mcf_trace 							>> output.txt
echo 										>> output.txt
./Gshare 8 5 gobmk_trace.txt						>> output.txt
./Gshare 4 2 gobmk_trace.txt						>> output.txt
./Gshare 3 1 gobmk_trace.txt						>> output.txt
echo -- END gobmk_trace 							>> output.txt
echo "--------------- END Test cases ---------------" 	>> output.txt
echo 										>> output.txt
echo "Loading . . . [1/4 trials finished]"
# 
# FIXED M @ 4		
echo "--------------- M Set to 4 ---------------" 	>> output.txt
echo "M	N	Miss %"		>> output.txt
./Gshare 4 1 mcf_trace.txt 						>> output.txt
./Gshare 4 2 mcf_trace.txt 						>> output.txt
./Gshare 4 3 mcf_trace.txt 						>> output.txt
./Gshare 4 4 mcf_trace.txt 						>> output.txt
echo -- END mcf_trace 							>> output.txt
echo 										>> output.txt
./Gshare 4 1 gobmk_trace.txt						>> output.txt
./Gshare 4 2 gobmk_trace.txt						>> output.txt
./Gshare 4 3 gobmk_trace.txt						>> output.txt
./Gshare 4 4 gobmk_trace.txt						>> output.txt
echo -- END gobmk_trace 							>> output.txt
echo "--------------- END M Set to 4 ---------------" 	>> output.txt
echo 										>> output.txt
echo "Loading . . . [2/4 trials finished]"
# 
# FIXED N @ 4		
echo "--------------- N Set to 4 ---------------" 	>> output.txt
echo "M	N	Miss %"							>> output.txt
./Gshare 4 4 mcf_trace.txt 						>> output.txt
./Gshare 5 4 mcf_trace.txt 						>> output.txt
./Gshare 6 4 mcf_trace.txt 						>> output.txt
./Gshare 7 4 mcf_trace.txt 						>> output.txt
echo  -- END mcf_trace 							>> output.txt
echo 										>> output.txt
./Gshare 4 4 gobmk_trace.txt						>> output.txt
./Gshare 5 4 gobmk_trace.txt						>> output.txt
./Gshare 6 4 gobmk_trace.txt						>> output.txt
./Gshare 7 4 gobmk_trace.txt						>> output.txt
echo -- END gobmk_trace 							>> output.txt
echo "--------------- END N Set to 4 ---------------" 	>> output.txt
echo 										>> output.txt
echo "Loading . . . [3/4 trials finished]"
# 
# FIXED N = 0		
echo "--------------- N Set to 0 ---------------" 	>> output.txt
echo "M	N	Miss %"							>> output.txt
./Gshare 4 0 mcf_trace.txt 						>> output.txt
./Gshare 5 0 mcf_trace.txt 						>> output.txt
./Gshare 6 0 mcf_trace.txt 						>> output.txt
./Gshare 7 0 mcf_trace.txt 						>> output.txt
echo -- END mcf_trace 							>> output.txt
echo 										>> output.txt
./Gshare 4 0 gobmk_trace.txt						>> output.txt
./Gshare 5 0 gobmk_trace.txt						>> output.txt
./Gshare 6 0 gobmk_trace.txt						>> output.txt
./Gshare 7 0 gobmk_trace.txt						>> output.txt
echo -- END gobmk_trace 							>> output.txt
echo "--------------- END N Set to 0 ---------------" 	>> output.txt
echo 										>> output.txt
echo "Loading . . . [4/4 trials finished]"
echo
echo "Outputs for each trial have been logged in a single file, output.txt
	located in your current working directory"
echo