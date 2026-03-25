#include <stdio.h>

int main(void) {
	int n;
	int scores[10];
	int i;

	printf("n = ");

	if (scanf("%d", &n) != 1) {
		return 0;
	}

	if (n <= 0 || n >= 10) {
		printf("ERROR: invalid number of students (%d)\n", n);
		return 0;
	}

	printf("scores = ");

	for (i = 0; i < n; i++) {
		if (scanf("%d", &scores[i]) != 1) {
			return 0;
		}

		if (scores[i] < -1 || scores[i] > 100) {
			printf("ERROR: invalid score (%d)\n", scores[i]);
			return 0;
		}
	}
	// printf("\n");

	{
		int passed = 0;
		int valid_count = 0;
		int max = 0;
		int min = 0;
		int sum = 0;
		int pass_rate;
		double ave;

		for (i = 0; i < n; i++) {
			if (scores[i] >= 60) {
				passed++;
			}

			if (scores[i] != -1) {
				if (valid_count == 0) {
					max = scores[i];
					min = scores[i];
				} else {
					if (scores[i] > max) {
						max = scores[i];
					}
					if (scores[i] < min) {
						min = scores[i];
					}
				}
				sum += scores[i];
				valid_count++;
			}
		}

		pass_rate = passed * 100 / n;
		if (valid_count == 0) {
			ave = 0.0;
			max = 0;
			min = 0;
		} else {
			ave = (double)sum / valid_count;
		}

		printf("======== score info ========\n");
		printf("#students = %d\n", n);
		printf("#passed = %d (%d%%)\n\n", passed, pass_rate);
		printf("ave = %.1f\n", ave);
		printf("max = %d\n", max);
		printf("min = %d\n", min);
		printf("============================\n");
	}

	return 0;
}
