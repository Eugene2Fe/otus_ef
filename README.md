## hw 09

Use key --multi-thread for run in multi threads
Use key --single-thread for run in 1 thread

examples:
./topk_words ../book.txt ../book.txt ../book.txt ../book.txt ../book.txt --single-thread
./topk_words ../book.txt ../book.txt ../book.txt ../book.txt ../book.txt --multi-thread

-=-=-=-=-=-
My perfomance test: (MacBook Air M1)

eugenefe@mac build % ./topk_words ../book.txt ../book.txt ../book.txt ../book.txt ../book.txt --single-thread 
11775 the
7375 and
6910 a
5540 to
5520 of
4980 i
3905 in
3835 he
3745 was
2615 that
Elapsed time is 380547 us
-=-=-=-=-=-
eugenefe@mac build % ./topk_words ../book.txt ../book.txt ../book.txt ../book.txt ../book.txt --multi-thread 
11775 the
7375 and
6910 a
5540 to
5520 of
4980 i
3905 in
3835 he
3745 was
2615 that
Elapsed time is 172294 us