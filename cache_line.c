#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec - t1.tv_nsec < 0) {
        diff.tv_sec = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main(int argc, char* argv[])
{

    struct timespec start, end;
    FILE* fp = fopen("result.txt", "a");

    for (int array_size = 256; array_size <= 10000; array_size++) {
        int repeat_times = 1000000;
        long array[array_size];
        for (int i = 0; i < array_size; i++) {
            array[i] = 0;
        }
        int j = 0;
        int k = 0;
        int c = 0;
        clock_gettime(CLOCK_REALTIME, &start);
        while (j++ < repeat_times) {
            if (k == array_size) {
                k = 0;
            }
            c = array[k++];
        }
        clock_gettime(CLOCK_REALTIME, &end);
        fprintf(fp, "%lf\n", diff_in_second(start, end));
    }

    fclose(fp);
    return 0;
}
