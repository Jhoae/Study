#include <iostream>

using namespace std;

int main()
{
	/* 	Array 없이 작성			 */
	const int num_students = 5;
	int score0 = 84;
	int score1 = 92;
	int score2 = 76;
	int score3 = 81;
	int score4 = 56;

	int total_score = score0 + score1 + score2 + score3 + score4;

	double avg_score = static_cast<double>(total_score) / num_students;
	// Note:: double(total_score) / num_students != double(total_score / num_students);



	/*  Array 사용 */
	const int num_students2 = 5;

	int scores[num_students2] = { 84,92,76,81,56 };

	int total_score_arr = 0;
	for (int i = 0; i < num_students2; ++i)
	{
		total_score_arr += scores[i];
	}
	double avg_score2 = static_cast<double>(total_score_arr) / num_students2;


	/* Array의 size 구하는 방법			*/
	const int num_students3 = sizeof(scores) / sizeof(int); // 5
	cout << num_students3 << endl;



	/* Array 의 max와 min 구하기 예시		 */

	const int num_students4 = 5;

	int scores4[num_students4] = { 84,92,76,81,56 };

	int max_score = 0;
	int min_score = 999;
	int total_score_arr4 = 0;

	for (int i = 0; i < num_students4; ++i)
	{
		total_score_arr4 += scores4[i];

		if (max_score < scores4[i]) max_score = scores4[i];
		//max_score = (max_score < scores4[i]) ? scores4[i] : max_score;

		if (min_score > scores4[i]) min_score = scores4[i];
		//min_score = (min_score > scores4[i]) ? scores4[i] : mix_score;

	}

	double avg_score4 = static_cast<double>(total_score_arr4) / num_students4;

	cout << max_score << endl;
	cout << min_score << endl;

	return 0;
}