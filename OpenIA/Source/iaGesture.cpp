/*
*This work is dual-licensed under BSD-3 and Apache License 2.0. 

*You can choose between one of them if you use this work.

*SPDX-License-Identifier: BSD-3-Clause OR Apache License 2.0

*/
#include "iaGesture.h"
#include <fstream>
#include <string>
#include <ctime>

JointPosition referdata;


double CalculateDynamicTimeWarpedAngle(vector<double> userdata, vector<double> referencedata, int userdata_size, int referdata_size);

//myGesture
double CalculateEuclideanDistance(double x, double y);
double CalculateDynamicTimeWarpedDistance(double userdata[][3], double referencedata[][3]);
double CalDynamicdataDynamicTimeWarpedDistance(vector<vector<vector<double>>> userdata, vector<vector<vector<double>>> referencedata, int movjointnum, int keyframcnt);
double CalculateDynamicTimeWarpedAxis(vector<gst::Bodypos> userdata, vector<gst::Bodypos> referencedata, int userdata_size, int referdata_size);
int CalDynamicdataLDT(const JointPos *userdat, const JointPos *referdata, vector<int> movingjoint,int jointnum, int usersize, int refersize, double thresholdist);
int CalDynamicMSdataLDT(const JointPos *userdata, const JointPos *referdata, vector<int> movingjoint, int jointnum, int usersize, int refersize, double thresholdist);
void reshape(double input[][3], double *output);
void GestureposdataSave(const JointPosition &jpos);
int findminresult(const double* result,int size);
int findintminresult(const int* result, int size);
void GesturAvgdataSave(const JointPosition &jpos);
void GestureposdataDycheck(const JointPosition &refer);
void GesturCovdatacheck(const JointPosition &refer);
void GesreferdataDycheck(const JointPosition &refer);
int findintminresult(vector<int> result, int size);
int findintminresult_t(vector<double> result, int size);

int CalDynamicMHADdataLDT(const std::vector < std::vector<gst::Bodypos>> userdata, const std::vector < std::vector<gst::Bodypos>> referdata, const std::vector<int>  movingjoint,int movingjointnum, int usersize, int refersize, double thresholdist);
void GestureRecognition::gesturerecog(JointPosition &jpos)
{

	referdata.loadGeNQuatdata();
	
	while (1) {
		if (jpos.dataGet)
		{
			cout << "gesture working" << endl;
			//referdata.GeNQuatdata();
			//referdata.GenDatacontrol[0]->pos_check();
			referdata.GenDatacontrol[0]->data_sample();
			referdata.GenDatacontrol[1]->data_sample();
			referdata.GenDatacontrol[2]->data_sample();
			referdata.GenDatacontrol[3]->data_sample();
			referdata.GenDatacontrol[4]->data_sample();
		

//			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//				//jpos.calavg();
//				//double result[10];
//				////////////////////////////////static pose test
//				//for (int k = 0; k < 10; k++)
//				//{
//				//	//result[k] = CalculateDynamicTimeWarpedDistance(referdata.referencepose[r], referdata.referencepose[k]);
//				//	result[k] = CalculateDynamicTimeWarpedDistance(jpos.avg, referdata.referencepose[k]);
//
//
//				//	// Dynamic
//
//				//
//				//
//				//
//				////result[1]=CalculateDynamicTimeWarpedDistance(jpos.avg, referdata.Bothhandup);
//
//				////result[0] = CalculateDynamicTimeWarpedDistance(referdata.Test, referdata.Tposdata);
//				////result[1] = CalculateDynamicTimeWarpedDistance(referdata.Test, referdata.Bothhandup);
//
//				////cout << "gesture dis - similarity T-pose :  " << result[0] << "    gesture di s- similarity Both-pose :  " << result[1] << endl;
//				//	cout << referdata.posename[k] <<"\t :  " <<result[k] <<" \n";
//				//}
//				//int p = 0;
//
//				//p = findminresult(result, sizeof(result) / sizeof(double));
//
//				////cout << "\n\n"<<referdata.posename[r] << " testing   \t  Result:   " << referdata.posename[p]<<endl;
//				//cout << "\n\n testing   \t  Result:   " << referdata.posename[p] << endl;
//				////////////////////////////////////////////////////static pose test
//
//
//				/*
//				testnum++;
//				}*/
//
//				//GesreferdataDycheck(referdata);
//			//	GestureposdataSave(jpos);
//				//GesturCovdatacheck(referdata);
//				//GesturAvgdataSave(referdata);
//
//				//cout << sizeof(referdata.Tposdata)/sizeof(double) << endl;
//
//			/*	jpos.calavg();
//				jpos.calvar();
//				sprintf_s(fileName, ".\\GestureData\\jointsVarData-00%d-%d%d%d.txt", jpos.maxframe, tm_local->tm_hour, tm_local->tm_min, tm_local->tm_sec);
//				skelitonDataFile.open(fileName);
//
//
//				skelitonDataFile << "Frames:" << "\t" << jpos.maxframe << "\n";
//
//				for (int tCount = 0; tCount < 16; tCount++)
//				{
//					skelitonDataFile
//						<< jpos.variance[tCount][0] << "\t" << jpos.variance[tCount][1] << "\t" << jpos.variance[tCount][2] << "\n";
//
//
//
//				}*/
//
//

				jpos.dataGet = false;

			


		}



	}
}
double CalculateEuclideanDistance(double x, double y) {
	return abs(x - y);
	//return std::sqrt(std::pow((x - y), 2));
}

double L2Norm(Eigen::Vector3f user, Eigen::Vector3f refer) {
	//return abs(x - y);
	return std::sqrt(std::pow((user[0] - refer[0]), 2)+ std::pow((user[1] - refer[1]), 2)+ std::pow((user[2] - refer[2]), 2));
}
double L2Norm_MHAD(gst::Bodypos user, gst::Bodypos refer) {
	//return abs(x - y);
	return std::sqrt(std::pow((user.x - refer.x), 2) + std::pow((user.y - refer.y), 2) + std::pow((user.z - refer.z), 2));
}
int findminresult(const double* result,int size)
{
	double buf=NULL;
	int idxnum ;
	bool firstvalue = true;
	int j = 0;
	while(1)
	{

		buf = result[j];
		idxnum = j;

		j++;
		if (buf != NULL)
			break;

	} 

	for (int i = 0; i < size; i++)
	{
		if (buf > result[i])
		{
			buf = result[i];
			idxnum = i;					
		}
		
	}
	//cout <<"check idxnum"<< idxnum << endl;

	return idxnum;




}
int findintminresult(const int* result, int size)
{
	int buf = NULL;
	int idxnum;
	bool firstvalue = true;
	int j = 0;
	while (1)
	{

		buf = result[j];
		idxnum = j;

		j++;
		if (buf != NULL)
			break;

	}

	for (int i = 0; i < size; i++)
	{
		if (buf > result[i])
		{
			buf = result[i];
			idxnum = i;
		}

	}
	//cout <<"check idxnum"<< idxnum << endl;

	return idxnum;




}
int findintminresult(vector<int> result, int size)
{
	
	int idxnum=0;
		
	int firstvalue = result[0];

	for (int i = 1; i < size; i++)
	{
		if (firstvalue > result[i])
		{
			firstvalue = result[i];
			idxnum = i;
		}

	}	
	//cout << idxnum <<"size"<< size <<endl;
	return idxnum;			
}
int findintminresult_t(vector<double> result, int size)
{

	int idxnum = 0;

	double firstvalue = result[0];

	for (int i = 1; i < size; i++)
	{
		if (firstvalue > result[i])
		{
			firstvalue = result[i];
			idxnum = i;
		}

	}
	//cout << idxnum <<"size"<< size <<endl;
	return idxnum;
}

double CalDynamicdataDynamicTimeWarpedDistance(vector<vector<vector<double>>> userdata, vector<vector<vector<double>>> referencedata, int movjointnum,int keyframcnt)
{
	 // userdata [ joint ] [ keyframe ] [ x,y,z] 

	

	//double cost[3][16][16];
	double joint_result=0;
	//vector<double> joint_result(movjointnum);

	for (int joint = 0; joint < movjointnum; joint++) {

		
		double result = 0;
		for (int coord = 0; coord < 3; coord++) {
			vector<vector<double>> cost(keyframcnt, vector<double>(keyframcnt));

			cost[0][0] = CalculateEuclideanDistance(userdata[joint][0][coord], referencedata[joint][0][coord]);

			// Calculate the first row:
			for (int i = 1; i < keyframcnt; i++) {
				cost[i][0] = cost[i - 1][0] + CalculateEuclideanDistance(userdata[joint][i][coord], referencedata[joint][0][coord]);
			}

			// Calculate the first column:
			for (int j = 1; j < keyframcnt; j++) {
				cost[0][j] = cost[0][j - 1] + CalculateEuclideanDistance(userdata[joint][0][coord], referencedata[joint][j][coord]);
			}

			// Fill the matrix:
			for (int i = 1; i < keyframcnt; i++) {
				for (int j = 1; j < keyframcnt; j++) {

					cost[i][j] = std::min(cost[i - 1][j], std::min(cost[i][j - 1], cost[i - 1][j - 1]))
						+ CalculateEuclideanDistance(userdata[joint][i][coord], referencedata[joint][j][coord]);
				}
			}

			result+=cost[keyframcnt - 1][keyframcnt - 1];
		}
		//joint_result[joint] = cost[keyframcnt-1][keyframcnt-1];
		joint_result += result;
	}

	//double return_val = cost[0][m - 1][n - 1] + cost[1][m - 1][n - 1] + cost[2][m - 1][n - 1];
	return joint_result;
}
int CalDynamicMSdataLDT(const JointPos *userdata, const JointPos *referdata, vector<int> movingjoint, int jointnum, int usersize, int refersize, double thresholdist)
{
	int jntnum = 4;

	int result = 0;
	for (int joint = 2; joint < jntnum; joint++) {

		// userdata [ joint ] [ keyframe ] [ x,y,z] 
		int **Darry = new int*[usersize + 1];

		for (int i = 0; i < usersize + 1; i++)
			Darry[i] = new int[refersize + 1];

		// array setting

		for (int userdataidx = 0; userdataidx < usersize + 1; userdataidx++)
		{
			Darry[userdataidx][0] = userdataidx;
		}
		for (int referdataidx = 0; referdataidx < refersize + 1; referdataidx++)
		{
			Darry[0][referdataidx] = referdataidx;
		}

		int subcost;
		for (int userdataidx = 0; userdataidx < usersize; userdataidx++)
		{
			for (int referdataidx = 0; referdataidx < refersize; referdataidx++)
			{
				//(L2Norm(userdata[userdataidx].Jointspos[movingjoint[joint]], referdata[referdataidx].Jointspos[movingjoint[joint]]) < thresholdist)
				//(L2Norm(userdata[userdataidx].Jointspos[joint], referdata[referdataidx].Jointspos[joint]) < thresholdist)
				if (L2Norm(userdata[userdataidx].Jointspos[joint], referdata[referdataidx].Jointspos[joint]) < thresholdist)
				{
					subcost = 0;
				}
				else {
					subcost = 1;
				}
				Darry[userdataidx + 1][referdataidx + 1] = std::min(Darry[userdataidx][referdataidx + 1] + 1, min(Darry[userdataidx + 1][referdataidx] + 1, Darry[userdataidx][referdataidx] + subcost));



			}

		}
		//cout << "here22" << endl;
		result += Darry[usersize][refersize];
		//	if (joint == 0||joint==1)
		//	{
		//		for (int userdataidx = 0; userdataidx < usersize + 1; userdataidx++)
		//		{
		//			for (int referdataidx = 0; referdataidx < refersize + 1; referdataidx++)
		//			{
		//				cout << Darry[userdataidx][referdataidx] << "\t";
		//			}
		//			cout << endl;
		//		}
		//		
		//
		//
		//}


			//cout << "here33" << endl;
	}
	return result;
}

//int CalDynamicMHADdataLDT(const std::vector < std::vector<gst::Bodypos>> userdata, const std::vector < std::vector<gst::Bodypos>> referdata, int jointnum, int usersize, int refersize, double thresholdist)
//{
//
//	int result = 0;
//	for (int joint = 2; joint < jointnum; joint++) {
//
//		// userdata [ joint ] [ keyframe ] [ x,y,z] 
//		int **Darry = new int*[usersize + 1];
//
//		for (int i = 0; i < usersize + 1; i++)
//			Darry[i] = new int[refersize + 1];
//
//		// array setting
//
//		for (int userdataidx = 0; userdataidx < usersize + 1; userdataidx++)
//		{
//			Darry[userdataidx][0] = userdataidx;
//		}
//		for (int referdataidx = 0; referdataidx < refersize + 1; referdataidx++)
//		{
//			Darry[0][referdataidx] = referdataidx;
//		}
//		
//		int subcost;
//		for (int userdataidx = 0; userdataidx < usersize; userdataidx++)
//		{
//			for (int referdataidx = 0; referdataidx < refersize; referdataidx++)
//			{
//				//(L2Norm(userdata[userdataidx].Jointspos[movingjoint[joint]], referdata[referdataidx].Jointspos[movingjoint[joint]]) < thresholdist)
//				//(L2Norm(userdata[userdataidx].Jointspos[joint], referdata[referdataidx].Jointspos[joint]) < thresholdist)
//				if (L2Norm_MHAD(userdata[userdataidx][joint], referdata[referdataidx][joint]) < thresholdist)
//				{
//					subcost = 0;
//				}
//				else {
//					subcost = 1;
//				}
//				Darry[userdataidx + 1][referdataidx + 1] = std::min(Darry[userdataidx][referdataidx + 1] + 1, min(Darry[userdataidx + 1][referdataidx] + 1, Darry[userdataidx][referdataidx] + subcost));
//
//
//
//			}
//
//		}
//		//cout << "here22" << endl;
//		result += Darry[usersize][refersize];
//		
//	}
//	return result;
//}
int CalDynamicMHADdataLDT(const std::vector < std::vector<gst::Bodypos>> userdata, const std::vector < std::vector<gst::Bodypos>> referdata, const std::vector<int>  movingjoint, int movingjointnum,int usersize, int refersize, double thresholdist)
{

	int result = 0;

	int movingjointnum_t = 10;
	//cout <<"Movingjoin num"<< movingjointnum <<endl;
	for (int joint = 0; joint < movingjointnum; joint++) {

		// userdata [ joint ] [ keyframe ] [ x,y,z] 
		int **Darry = new int*[usersize + 1];

		for (int i = 0; i < usersize + 1; i++)
			Darry[i] = new int[refersize + 1];

		// array setting

		for (int userdataidx = 0; userdataidx < usersize + 1; userdataidx++)
		{
			Darry[userdataidx][0] = userdataidx;
		}
		for (int referdataidx = 0; referdataidx < refersize + 1; referdataidx++)
		{
			Darry[0][referdataidx] = referdataidx;
		}

		int subcost;
		for (int userdataidx = 0; userdataidx < usersize; userdataidx++)
		{
			for (int referdataidx = 0; referdataidx < refersize; referdataidx++)
			{
				//(L2Norm(userdata[userdataidx].Jointspos[movingjoint[joint]], referdata[referdataidx].Jointspos[movingjoint[joint]]) < thresholdist)
				//(L2Norm(userdata[userdataidx].Jointspos[joint], referdata[referdataidx].Jointspos[joint]) < thresholdist)
				//if (L2Norm_MHAD(userdata[userdataidx][joint], referdata[referdataidx][joint]) < thresholdist)
				if (L2Norm_MHAD(userdata[userdataidx][movingjoint[joint]], referdata[referdataidx][movingjoint[joint]]) < thresholdist)
				{
					subcost = 0;
				}
				else {
					subcost = 1;
				}
				Darry[userdataidx + 1][referdataidx + 1] = std::min(Darry[userdataidx][referdataidx + 1] + 1, min(Darry[userdataidx + 1][referdataidx] + 1, Darry[userdataidx][referdataidx] + subcost));



			}

		}
		//cout << "here22" << endl;
		result += Darry[usersize][refersize];

	}
	return result;
}
int CalDynamicdataLDT(const JointPos *userdata, const JointPos *referdata, vector<int> movingjoint,int jointnum, int usersize, int refersize, double thresholdist)
{
	
	int result = 0;
	for(int joint =0;joint< jointnum;joint++){

	// userdata [ joint ] [ keyframe ] [ x,y,z] 
	int **Darry = new int*[usersize+1];

	for (int i = 0; i < usersize+1; i++)
		Darry[i] = new int[refersize+1];

	// array setting
	
	for (int userdataidx = 0; userdataidx < usersize+1; userdataidx++)
	{		
		Darry[userdataidx][0] = userdataidx;		
	}
	for (int referdataidx = 0; referdataidx < refersize+1; referdataidx++)
	{
		Darry[0][referdataidx] = referdataidx;
	}
	
	int subcost;
	for (int userdataidx = 0; userdataidx < usersize; userdataidx++)
	{
		for (int referdataidx = 0; referdataidx < refersize; referdataidx++)
		{
			//(L2Norm(userdata[userdataidx].Jointspos[movingjoint[joint]], referdata[referdataidx].Jointspos[movingjoint[joint]]) < thresholdist)
			//(L2Norm(userdata[userdataidx].Jointspos[joint], referdata[referdataidx].Jointspos[joint]) < thresholdist)
			if (L2Norm(userdata[userdataidx].Jointspos[movingjoint[joint]], referdata[referdataidx].Jointspos[movingjoint[joint]]) < thresholdist)
			{
				subcost = 0;
			}
			else {
				subcost = 1;
			}
			Darry[userdataidx+1][referdataidx+1] = std::min(Darry[userdataidx][referdataidx+1] + 1, min(Darry[userdataidx+1][referdataidx] + 1, Darry[userdataidx][referdataidx] + subcost));
			
			
			
		}

	}
	//cout << "here22" << endl;
	result += Darry[usersize][refersize];
//	if (joint == 0||joint==1)
//	{
//		for (int userdataidx = 0; userdataidx < usersize + 1; userdataidx++)
//		{
//			for (int referdataidx = 0; referdataidx < refersize + 1; referdataidx++)
//			{
//				cout << Darry[userdataidx][referdataidx] << "\t";
//			}
//			cout << endl;
//		}
//		
//
//
//}


	//cout << "here33" << endl;
	}
	return result;
}


double CalculateDynamicTimeWarpedAxis(vector<gst::Bodypos> userdata, vector<gst::Bodypos> referencedata, int userdata_size, int referdata_size)
{



	//double cost[userdata_size][userdata_size];
	std::vector<std::vector<double>> cost(userdata_size, std::vector<double>(referdata_size));
	// Allocate the Matrix to work on:
	//std::vector<std::vector<double>> cost(m, std::vector<double>(n));

	/*for (int i = 1; i < 5; i++) {
		cout << referencedata[i]<<endl;
	}*/
	/*cout <<"size : " <<userdata_size <<" , "<< referdata_size << endl;
	cout << "cost size : " << cost.size() << endl;*/
	cost[0][0] = L2Norm_MHAD(userdata[0], referencedata[0]);

	// Calculate the first row:
	for (int i = 1; i < userdata_size; i++) {
		cost[i][0] = cost[i - 1][0] + L2Norm_MHAD(userdata[i], referencedata[0]);
	}

	// Calculate the first column:
	for (int j = 1; j < referdata_size; j++) {
		cost[0][j] = cost[0][j - 1] + L2Norm_MHAD(userdata[0], referencedata[j]);
	}

	// Fill the matrix:
	for (int i = 1; i < userdata_size; i++) {
		for (int j = 1; j < referdata_size; j++) {

			cost[i][j] = std::min(cost[i - 1][j], std::min(cost[i][j - 1], cost[i - 1][j - 1]))
				+ L2Norm_MHAD(userdata[i], referencedata[j]);
		}
	}



	double return_val = cost[userdata_size - 1][referdata_size - 1];
	return return_val;
}




double CalculateDynamicTimeWarpedAngle(vector<double> userdata,vector<double> referencedata, int userdata_size, int referdata_size)
{



	//double cost[userdata_size][userdata_size];
	std::vector<std::vector<double>> cost(userdata_size, std::vector<double>(referdata_size));
	// Allocate the Matrix to work on:
	//std::vector<std::vector<double>> cost(m, std::vector<double>(n));

	/*for (int i = 1; i < 5; i++) {
		cout << referencedata[i]<<endl;
	}*/
	/*cout <<"size : " <<userdata_size <<" , "<< referdata_size << endl;
	cout << "cost size : " << cost.size() << endl;*/
		cost[0][0] = CalculateEuclideanDistance(userdata[0], referencedata[0]);

		// Calculate the first row:
		for (int i = 1; i < userdata_size; i++) {
			cost[i][0] = cost[i - 1][0] + CalculateEuclideanDistance(userdata[i], referencedata[0]);
		}

		// Calculate the first column:
		for (int j = 1; j < referdata_size; j++) {
			cost[0][j] = cost[0][j - 1] + CalculateEuclideanDistance(userdata[0], referencedata[j]);
		}

		// Fill the matrix:
		for (int i = 1; i < userdata_size; i++) {
			for (int j = 1; j < referdata_size; j++) {

				cost[i][j] = std::min(cost[i - 1][j], std::min(cost[i][j - 1], cost[i - 1][j - 1]))
					+ CalculateEuclideanDistance(userdata[i], referencedata[j]);
			}
		}

	

	double return_val = cost[userdata_size - 1][referdata_size - 1];
	return return_val;
}

double CalculateDynamicTimeWarpedDistance(double userdata[][3], double referencedata[][3])
{

	size_t m = 16;
	size_t n = 16;
	//cout <<" userdat size :  "<< sizeof(*userdata) << endl;
	/*double user [48];
	double refer[48];

	reshape(userdata,user);
	reshape(referencedata,refer);*/

	double cost[3][16][16];

	// Allocate the Matrix to work on:
	//std::vector<std::vector<double>> cost(m, std::vector<double>(n));


	for (int k=0; k<3;k++){
	cost[k][0][0] = CalculateEuclideanDistance(userdata[0][k], referencedata[0][k]);

	// Calculate the first row:
	for (int i = 1; i < m; i++) {
		cost[k][i][0] = cost[k][i - 1][0] + CalculateEuclideanDistance(userdata[i][k], referencedata[0][k]);
	}

	// Calculate the first column:
	for (int j = 1; j < n; j++) {
		cost[k][0][j] = cost[k][0][j - 1] + CalculateEuclideanDistance(userdata[0][k], referencedata[j][k]);
	}

	// Fill the matrix:
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {

			cost[k][i][j] = std::min(cost[k][i - 1][j], std::min(cost[k][i][j - 1], cost[k][i - 1][j - 1]))
				+ CalculateEuclideanDistance(userdata[i][k], referencedata[j][k]);
		}
	}

	}

	double return_val = cost[0][m - 1][n - 1] + cost[1][m - 1][n - 1] + cost[2][m - 1][n - 1];
	return return_val;
}

void reshape(double input[][3], double *output)
{
	
	int k = 0;
	for (int i = 0; i < 48 / 3; i++)
	{
		for (int j = 0; j <  3; j++)
		{
			output[k] = input[i][j];

			//cout << k << "data test " << output[k] << endl;
				k++;

				
		}
	}
	
}

void GestureposdataSave(const JointPosition &jpos)
{
	time_t curr_time;
	curr_time = time(NULL);
	tm *tm_local = localtime(&curr_time);

	ofstream skelitonDataFile;
	char fileName[1024];


	sprintf_s(fileName, ".\\GestureData\\jointsPosData-00%d-%d%d%d.txt", jpos.maxframe, tm_local->tm_hour, tm_local->tm_min, tm_local->tm_sec);
	skelitonDataFile.open(fileName);


	skelitonDataFile << "Frames:" << "\t" << jpos.maxframe << "\n";


	for (int tCount = 0; tCount < jpos.maxframe; tCount++)
	{
		//referdata.referencepose[r]
		skelitonDataFile
			<< jpos.posData[tCount].Jointspos[0][0] << "\t" << jpos.posData[tCount].Jointspos[0][1] << "\t" << jpos.posData[tCount].Jointspos[0][2] << "\t"
			<< jpos.posData[tCount].Jointspos[1][0] << "\t" << jpos.posData[tCount].Jointspos[1][1] << "\t" << jpos.posData[tCount].Jointspos[1][2] << "\t"
			<< jpos.posData[tCount].Jointspos[2][0] << "\t" << jpos.posData[tCount].Jointspos[2][1] << "\t" << jpos.posData[tCount].Jointspos[2][2] << "\t"
			<< jpos.posData[tCount].Jointspos[3][0] << "\t" << jpos.posData[tCount].Jointspos[3][1] << "\t" << jpos.posData[tCount].Jointspos[3][2] << "\t"
			<< jpos.posData[tCount].Jointspos[4][0] << "\t" << jpos.posData[tCount].Jointspos[4][1] << "\t" << jpos.posData[tCount].Jointspos[4][2] << "\t"
			<< jpos.posData[tCount].Jointspos[5][0] << "\t" << jpos.posData[tCount].Jointspos[5][1] << "\t" << jpos.posData[tCount].Jointspos[5][2] << "\t"
			<< jpos.posData[tCount].Jointspos[6][0] << "\t" << jpos.posData[tCount].Jointspos[6][1] << "\t" << jpos.posData[tCount].Jointspos[6][2] << "\t"
			<< jpos.posData[tCount].Jointspos[7][0] << "\t" << jpos.posData[tCount].Jointspos[7][1] << "\t" << jpos.posData[tCount].Jointspos[7][2] << "\t"
			<< jpos.posData[tCount].Jointspos[8][0] << "\t" << jpos.posData[tCount].Jointspos[8][1] << "\t" << jpos.posData[tCount].Jointspos[8][2] << "\t"
			<< jpos.posData[tCount].Jointspos[9][0] << "\t" << jpos.posData[tCount].Jointspos[9][1] << "\t" << jpos.posData[tCount].Jointspos[9][2] << "\t"
			<< jpos.posData[tCount].Jointspos[10][0] << "\t" << jpos.posData[tCount].Jointspos[10][1] << "\t" << jpos.posData[tCount].Jointspos[10][2] << "\t"
			<< jpos.posData[tCount].Jointspos[11][0] << "\t" << jpos.posData[tCount].Jointspos[11][1] << "\t" << jpos.posData[tCount].Jointspos[11][2] << "\t"
			<< jpos.posData[tCount].Jointspos[12][0] << "\t" << jpos.posData[tCount].Jointspos[12][1] << "\t" << jpos.posData[tCount].Jointspos[12][2] << "\t"
			<< jpos.posData[tCount].Jointspos[13][0] << "\t" << jpos.posData[tCount].Jointspos[13][1] << "\t" << jpos.posData[tCount].Jointspos[13][2] << "\t"
			<< jpos.posData[tCount].Jointspos[14][0] << "\t" << jpos.posData[tCount].Jointspos[14][1] << "\t" << jpos.posData[tCount].Jointspos[14][2] << "\t"
			<< jpos.posData[tCount].Jointspos[15][0] << "\t" << jpos.posData[tCount].Jointspos[15][1] << "\t" << jpos.posData[tCount].Jointspos[15][2] << "\n";
	}




	skelitonDataFile.close();






}

void GesturAvgdataSave(const JointPosition &jpos)
{
	time_t curr_time;
	curr_time = time(NULL);
	tm *tm_local = localtime(&curr_time);

	ofstream skelitonDataFile;
	char fileName[1024];


	sprintf_s(fileName, ".\\GestureData\\AVGData-00%d-%d%d%d.txt", jpos.maxframe, tm_local->tm_hour, tm_local->tm_min, tm_local->tm_sec);
	skelitonDataFile.open(fileName);


	//skelitonDataFile << "Frames:" << "\t" << jpos.maxframe << "\n";


	/*for (int tCount = 0; tCount < jpos.maxframe; tCount++)
	{
		skelitonDataFile
			<< jpos.posData[tCount].Jointspos[0][0] << "\t" << jpos.posData[tCount].Jointspos[0][1] << "\t" << jpos.posData[tCount].Jointspos[0][2] << "\t"
			<< jpos.posData[tCount].Jointspos[1][0] << "\t" << jpos.posData[tCount].Jointspos[1][1] << "\t" << jpos.posData[tCount].Jointspos[1][2] << "\t"
			<< jpos.posData[tCount].Jointspos[2][0] << "\t" << jpos.posData[tCount].Jointspos[2][1] << "\t" << jpos.posData[tCount].Jointspos[2][2] << "\t"
			<< jpos.posData[tCount].Jointspos[3][0] << "\t" << jpos.posData[tCount].Jointspos[3][1] << "\t" << jpos.posData[tCount].Jointspos[3][2] << "\t"
			<< jpos.posData[tCount].Jointspos[4][0] << "\t" << jpos.posData[tCount].Jointspos[4][1] << "\t" << jpos.posData[tCount].Jointspos[4][2] << "\t"
			<< jpos.posData[tCount].Jointspos[5][0] << "\t" << jpos.posData[tCount].Jointspos[5][1] << "\t" << jpos.posData[tCount].Jointspos[5][2] << "\t"
			<< jpos.posData[tCount].Jointspos[6][0] << "\t" << jpos.posData[tCount].Jointspos[6][1] << "\t" << jpos.posData[tCount].Jointspos[6][2] << "\t"
			<< jpos.posData[tCount].Jointspos[7][0] << "\t" << jpos.posData[tCount].Jointspos[7][1] << "\t" << jpos.posData[tCount].Jointspos[7][2] << "\t"
			<< jpos.posData[tCount].Jointspos[8][0] << "\t" << jpos.posData[tCount].Jointspos[8][1] << "\t" << jpos.posData[tCount].Jointspos[8][2] << "\t"
			<< jpos.posData[tCount].Jointspos[9][0] << "\t" << jpos.posData[tCount].Jointspos[9][1] << "\t" << jpos.posData[tCount].Jointspos[9][2] << "\t"
			<< jpos.posData[tCount].Jointspos[10][0] << "\t" << jpos.posData[tCount].Jointspos[10][1] << "\t" << jpos.posData[tCount].Jointspos[10][2] << "\t"
			<< jpos.posData[tCount].Jointspos[11][0] << "\t" << jpos.posData[tCount].Jointspos[11][1] << "\t" << jpos.posData[tCount].Jointspos[11][2] << "\t"
			<< jpos.posData[tCount].Jointspos[12][0] << "\t" << jpos.posData[tCount].Jointspos[12][1] << "\t" << jpos.posData[tCount].Jointspos[12][2] << "\t"
			<< jpos.posData[tCount].Jointspos[13][0] << "\t" << jpos.posData[tCount].Jointspos[13][1] << "\t" << jpos.posData[tCount].Jointspos[13][2] << "\t"
			<< jpos.posData[tCount].Jointspos[14][0] << "\t" << jpos.posData[tCount].Jointspos[14][1] << "\t" << jpos.posData[tCount].Jointspos[14][2] << "\t"
			<< jpos.posData[tCount].Jointspos[15][0] << "\t" << jpos.posData[tCount].Jointspos[15][1] << "\t" << jpos.posData[tCount].Jointspos[15][2] << "\n";
	}
*/


	for (int pose = 10; pose < 19; pose++)
	{
		skelitonDataFile << " pose name  :  " << referdata.posename[pose] << "\n";


		for (int joint = 0; joint < 16; joint++)
		{

			

				//referdata.referencepose[pose][joint][coord];
				skelitonDataFile
					<< referdata.referencepose[pose][joint][0] << "\t" << referdata.referencepose[pose][joint][1] << "\t" << referdata.referencepose[pose][joint][2] << "\n";
			


		}




	}


	skelitonDataFile.close();






}

void GesturCovdatacheck(const JointPosition &refer)
{
	time_t curr_time;
	curr_time = time(NULL);
	tm *tm_local = localtime(&curr_time);

	ofstream skelitonDataFile;
	char fileName[1024];


	sprintf_s(fileName, ".\\GestureData\\ReferCovdata-00%d-%d%d%d.txt", refer.Dynamicdatacontrol.front()->maxframe, tm_local->tm_hour, tm_local->tm_min, tm_local->tm_sec);
	skelitonDataFile.open(fileName);

	for (auto i = refer.Dynamicdatacontrol.begin(); i != refer.Dynamicdatacontrol.end(); ++i)
	{
		//cout << (*i)->posename << " move index : ";
		skelitonDataFile << " pose name  :  " << (*i)->posename << "\n";


		for (int joint = 0; joint < 16; joint++)
		{



			//referdata.referencepose[pose][joint][coord];
			skelitonDataFile
				<< (*i)->variance[joint][0] << "\t" << (*i)->variance[joint][1] << "\t" << (*i)->variance[joint][2] << "\n";


		}


	}



	skelitonDataFile.close();




}
void GesreferdataDycheck(const JointPosition &refer)
{

	for (auto i = refer.Dynamicdatacontrol.begin(); i != refer.Dynamicdatacontrol.end(); ++i)
	{
		cout << (*i)->posename << " move index : ";
		

		for (auto j = (*i)->movingjoint.begin(); j != (*i)->movingjoint.end(); ++j)
		{

			cout << *j << " , ";
		}

		cout << endl;

		cout << " motion class : " << (*i)->motionclass << endl ;

		(*i)->keyframenum;

		for (auto j = (*i)->keyframenum.begin(); j != (*i)->keyframenum.end(); ++j)
		{

			cout << "Keyframe idx : ";
			for (auto k = (*j).begin(); k != (*j).end(); ++k)
			{
				cout << *k << " , ";

			}

			cout << endl;
		}






	}






}


void GestureposdataDycheck(const JointPosition &refer)
{
	time_t curr_time;
	curr_time = time(NULL);
	tm *tm_local = localtime(&curr_time);

	ofstream skelitonDataFile;
	char fileName[1024];

	//refer.Dynamicdatacontrol.front()->maxframe
	sprintf_s(fileName, ".\\GestureData\\DYDataCheck-00%d-%d%d%d.txt", refer.Dynamicdatacontrol.front()->maxframe, tm_local->tm_hour, tm_local->tm_min, tm_local->tm_sec);
	skelitonDataFile.open(fileName);


	skelitonDataFile << "Frames:" << "\t" << refer.Dynamicdatacontrol.front()->maxframe << "\n";
	//cout << " Dy size check"<< refer.Dynamicdatacontrol.size()<<endl;

	for (int tCount = 0; tCount < refer.Dynamicdatacontrol.front()->maxframe; tCount++)
	{

		//this->Dynamicdatacontrol.back()->posData[lineCount].Jointspos[0][0]
		//referdata.referencepose[r]
		skelitonDataFile
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[0][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[0][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[0][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[1][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[1][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[1][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[2][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[2][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[2][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[3][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[3][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[3][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[4][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[4][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[4][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[5][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[5][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[5][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[6][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[6][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[6][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[7][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[7][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[7][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[8][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[8][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[8][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[9][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[9][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[9][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[10][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[10][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[10][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[11][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[11][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[11][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[12][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[12][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[12][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[13][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[13][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[13][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[14][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[14][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[14][2] << "\t"
			<< refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[15][0] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[15][1] << "\t" << refer.Dynamicdatacontrol.front()->posData[tCount].Jointspos[15][2] << "\n";
	}
	

	skelitonDataFile.close();






}



/////////////////// data save

//time_t curr_time;
//curr_time = time(NULL);
//tm *tm_local = localtime(&curr_time);
//
//ofstream skelitonDataFile;
//char fileName[1024];
//
//
//sprintf_s(fileName, ".\\GestureData\\jointsPosData-00%d-%d%d%d.txt", jpos.maxframe, tm_local->tm_hour, tm_local->tm_min, tm_local->tm_sec);
//skelitonDataFile.open(fileName);
//
//
//skelitonDataFile << "Frames:" << "\t" << jpos.maxframe << "\n";
//
//
//for (int tCount = 0; tCount < jpos.maxframe; tCount++)
//{
//	skelitonDataFile
//		<< jpos.posData[tCount].Jointspos[0][0] << "\t" << jpos.posData[tCount].Jointspos[0][1] << "\t" << jpos.posData[tCount].Jointspos[0][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[1][0] << "\t" << jpos.posData[tCount].Jointspos[1][1] << "\t" << jpos.posData[tCount].Jointspos[1][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[2][0] << "\t" << jpos.posData[tCount].Jointspos[2][1] << "\t" << jpos.posData[tCount].Jointspos[2][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[3][0] << "\t" << jpos.posData[tCount].Jointspos[3][1] << "\t" << jpos.posData[tCount].Jointspos[3][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[4][0] << "\t" << jpos.posData[tCount].Jointspos[4][1] << "\t" << jpos.posData[tCount].Jointspos[4][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[5][0] << "\t" << jpos.posData[tCount].Jointspos[5][1] << "\t" << jpos.posData[tCount].Jointspos[5][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[6][0] << "\t" << jpos.posData[tCount].Jointspos[6][1] << "\t" << jpos.posData[tCount].Jointspos[6][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[7][0] << "\t" << jpos.posData[tCount].Jointspos[7][1] << "\t" << jpos.posData[tCount].Jointspos[7][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[8][0] << "\t" << jpos.posData[tCount].Jointspos[8][1] << "\t" << jpos.posData[tCount].Jointspos[8][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[9][0] << "\t" << jpos.posData[tCount].Jointspos[9][1] << "\t" << jpos.posData[tCount].Jointspos[9][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[10][0] << "\t" << jpos.posData[tCount].Jointspos[10][1] << "\t" << jpos.posData[tCount].Jointspos[10][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[11][0] << "\t" << jpos.posData[tCount].Jointspos[11][1] << "\t" << jpos.posData[tCount].Jointspos[11][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[12][0] << "\t" << jpos.posData[tCount].Jointspos[12][1] << "\t" << jpos.posData[tCount].Jointspos[12][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[13][0] << "\t" << jpos.posData[tCount].Jointspos[13][1] << "\t" << jpos.posData[tCount].Jointspos[13][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[14][0] << "\t" << jpos.posData[tCount].Jointspos[14][1] << "\t" << jpos.posData[tCount].Jointspos[14][2] << "\t"
//		<< jpos.posData[tCount].Jointspos[15][0] << "\t" << jpos.posData[tCount].Jointspos[15][1] << "\t" << jpos.posData[tCount].Jointspos[15][2] << "\n";
//}
//
//skelitonDataFile.close();

///////////////////////////////// data save



///////////////////////////////////prev dtw

//cost[0][0] = CalculateEuclideanDistance(userdata[0][0], userdata[0][0]);
//
//// Calculate the first row:
//for (int i = 1; i < m; i++) {
//	cost[i][0] = cost[i - 1][0] + CalculateEuclideanDistance(user[i], refer[0]);
//}
//
//// Calculate the first column:
//for (int j = 1; j < n; j++) {
//	cost[0][j] = cost[0][j - 1] + CalculateEuclideanDistance(user[0], refer[j]);
//}
//
//// Fill the matrix:
//for (int i = 1; i < m; i++) {
//	for (int j = 1; j < n; j++) {
//
//		cost[i][j] = std::min(cost[i - 1][j], std::min(cost[i][j - 1], cost[i - 1][j - 1]))
//			+ CalculateEuclideanDistance(user[i], refer[j]);
//	}
//}
//
//return cost[m - 1][n - 1];
//

///////////////////////////////////////////



//	//cout << "right  Check  : z " << rightFootLowerLeg.jointPoint[2] << "   z " << leftFootLowerLeg.jointPoint[2] << endl;
	//	double diffR = rightFootLowerLeg.jointPoint[1];
	//	double diffL = leftFootLowerLeg.jointPoint[1];





	//	//}

	//	rightKneeUpperLeg.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] - diffR;
	//	rightHipSegment.jointPoint[1] = rightHipSegment.jointPoint[1] - diffR;

	//	leftKneeUpperLeg.jointPoint[1] = leftKneeUpperLeg.jointPoint[1] - diffL;
	//	leftHipSegment.jointPoint[1] = leftHipSegment.jointPoint[1] - diffL;


	//	//---------------------------------------- Bottom-Up Update -----------------------------------------------
	//	//Finding right knee joint from the fixed right foot.
	//	quaternion q = avatar.b7;// .Inverse().mutiplication(avatar.b7);
	//	quaternion vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));

	//	rightKneeUpperLeg.jointPoint[0] = rightFootLowerLeg.jointPoint[0] + vec.mData[0] * rightFootLowerLeg.length;
	//	rightKneeUpperLeg.jointPoint[1] = 0 + vec.mData[2] * rightFootLowerLeg.length;
	//	rightKneeUpperLeg.jointPoint[2] = rightFootLowerLeg.jointPoint[2] + -vec.mData[1] * rightFootLowerLeg.length;

	//	//Finding left knee joint from the fixed left foot.
	//	q = avatar.b9;// .Inverse().mutiplication(avatar.b9);
	//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));

	//	leftKneeUpperLeg.jointPoint[0] = leftFootLowerLeg.jointPoint[0] + vec.mData[0] * leftFootLowerLeg.length;
	//	leftKneeUpperLeg.jointPoint[1] = 0 + vec.mData[2] * leftFootLowerLeg.length;
	//	leftKneeUpperLeg.jointPoint[2] = leftFootLowerLeg.jointPoint[2] + -vec.mData[1] * leftFootLowerLeg.length;

	//	//Finding right pelvis joint from the right knee.
	//	q = avatar.b6;// .Inverse().mutiplication(avatar.b6);
	//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));

	//	rightHipSegment.jointPoint[0] = rightKneeUpperLeg.jointPoint[0] + vec.mData[0] * rightKneeUpperLeg.length;
	//	rightHipSegment.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] + vec.mData[2] * rightKneeUpperLeg.length;
	//	rightHipSegment.jointPoint[2] = rightKneeUpperLeg.jointPoint[2] + -vec.mData[1] * rightKneeUpperLeg.length;

	//	//Finding left pelvis joint from the left knee.
	//	q = avatar.b8;// .Inverse().mutiplication(avatar.b8);
	//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));

	//	leftHipSegment.jointPoint[0] = leftKneeUpperLeg.jointPoint[0] + vec.mData[0] * leftKneeUpperLeg.length;
	//	leftHipSegment.jointPoint[1] = leftKneeUpperLeg.jointPoint[1] + vec.mData[2] * leftKneeUpperLeg.length;
	//	leftHipSegment.jointPoint[2] = leftKneeUpperLeg.jointPoint[2] + -vec.mData[1] * leftKneeUpperLeg.length;

	//	//Finding pelvis joint from the left and right pelvis.
	//	if (leftHipSegment.jointPoint[1] > rightHipSegment.jointPoint[1])
	//	{
	//		//cout <<"left " <<endl;
	//		q = avatar.b0;// .Inverse().mutiplication(avatar.b8);
	//		vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse()));

	//		pelvisStomach.jointPoint[0] = leftHipSegment.jointPoint[0] + vec.mData[0] * leftHipSegment.length;
	//		pelvisStomach.jointPoint[1] = leftHipSegment.jointPoint[1] + vec.mData[2] * leftHipSegment.length;
	//		pelvisStomach.jointPoint[2] = leftHipSegment.jointPoint[2] - vec.mData[1] * leftHipSegment.length;

	//		/*float diffR = leftHipSegment.jointPoint[1] - rightHipSegment.jointPoint[1];
	//		rightKneeUpperLeg.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] + diffR;
	//		rightFootLowerLeg.jointPoint[1] = rightFootLowerLeg.jointPoint[1] + diffR;
	//		rightHipSegment.jointPoint[1] = rightHipSegment.jointPoint[1] + diffR;

	//		diffR = leftHipSegment.jointPoint[2] - rightHipSegment.jointPoint[2];;
	//		rightKneeUpperLeg.jointPoint[2] = rightKneeUpperLeg.jointPoint[2] + diffR;
	//		rightFootLowerLeg.jointPoint[2] = rightFootLowerLeg.jointPoint[2] + diffR;
	//		rightHipSegment.jointPoint[2] = rightHipSegment.jointPoint[2] + diffR;*/

	//		//	isEqual = false;

	//	}
	//	else 	if (rightHipSegment.jointPoint[1] >= leftHipSegment.jointPoint[1])
	//	{
	//		//cout << "right " << endl;
	//		q = avatar.b0;// .Inverse().mutiplication(avatar.b8);
	//		vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse()));

	//		pelvisStomach.jointPoint[0] = rightHipSegment.jointPoint[0] + vec.mData[0] * rightHipSegment.length;
	//		pelvisStomach.jointPoint[1] = rightHipSegment.jointPoint[1] + vec.mData[2] * rightHipSegment.length;
	//		pelvisStomach.jointPoint[2] = rightHipSegment.jointPoint[2] - vec.mData[1] * rightHipSegment.length;
	//		//cout << pelvisStomach.jointPoint[0] << "," << pelvisStomach.jointPoint[1] << "," << pelvisStomach.jointPoint[2] << ",";

	//		/*float diffR = rightHipSegment.jointPoint[1] - leftHipSegment.jointPoint[1];
	//		leftKneeUpperLeg.jointPoint[1]	= leftKneeUpperLeg.jointPoint[1] + diffR;
	//		leftFootLowerLeg.jointPoint[1]	= leftFootLowerLeg.jointPoint[1] + diffR;
	//		leftHipSegment.jointPoint[1]	= leftHipSegment.jointPoint[1] + diffR;

	//		leftKneeUpperLeg.jointPoint[2]	= leftKneeUpperLeg.jointPoint[2] + diffR;
	//		leftFootLowerLeg.jointPoint[2]	= leftFootLowerLeg.jointPoint[2] + diffR;
	//		leftHipSegment.jointPoint[2]	= leftHipSegment.jointPoint[2]   + diffR;*/
	//		// isEqual = false;
	//	}
	//	/*else
	//	{
	//		pelvisStomach.jointPoint[0] = (rightHipSegment.jointPoint[0] + leftHipSegment.jointPoint[0]) / 2;
	//		pelvisStomach.jointPoint[1] = (rightHipSegment.jointPoint[1] + leftHipSegment.jointPoint[1]) / 2;
	//		pelvisStomach.jointPoint[2] = (rightHipSegment.jointPoint[2] + leftHipSegment.jointPoint[2]) / 2;
	//		diffR = rightHipSegment.jointPoint[2] - leftHipSegment.jointPoint[2];
	//		isEqual = true;
	//	}*/
	//	//cout << pelvisStomach.jointPoint[0] << "," << pelvisStomach.jointPoint[1] << "," << pelvisStomach.jointPoint[2]<<endl;
	////----------------------------------------Top-Down Update---------------------------------------------------------------------------------------
	//		//Finding right pelvis joint from the pelvis.
	//	q = avatar.b0;// .Inverse().mutiplication(avatar.b0);
	//	vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse()));

	//	rightHipSegment.jointPoint[0] = pelvisStomach.jointPoint[0] + vec.mData[0] * rightHipSegment.length;
	//	rightHipSegment.jointPoint[1] = pelvisStomach.jointPoint[1] + vec.mData[2] * rightHipSegment.length; //Changes in Lower body with pelvis rotation and model moves continously in z axis
	//	rightHipSegment.jointPoint[2] = pelvisStomach.jointPoint[2] - vec.mData[1] * rightHipSegment.length;//Changes in Lower body with pelvis rotation and model moves continously in z axis
	//	//cout << rightHipSegment.jointPoint[0] << "," << rightHipSegment.jointPoint[1] << "," << rightHipSegment.jointPoint[2] << ",";

	//	//Finding left pelvis joint from the pelvis.
	//	q = avatar.b0;// .Inverse().mutiplication(avatar.b0);
	//	vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse()));

	//	leftHipSegment.jointPoint[0] = pelvisStomach.jointPoint[0] + vec.mData[0] * leftHipSegment.length;
	//	leftHipSegment.jointPoint[1] = pelvisStomach.jointPoint[1] + vec.mData[2] * leftHipSegment.length;  //Changes in Lower body with pelvis rotation and model moves continously in z axis
	//	leftHipSegment.jointPoint[2] = pelvisStomach.jointPoint[2] - vec.mData[1] * leftHipSegment.length;	//Changes in Lower body with pelvis rotation and model moves continously in z axis
	//	//cout << leftHipSegment.jointPoint[0] << "," << leftHipSegment.jointPoint[1] << "," << leftHipSegment.jointPoint[2] << ",";

	////if (!isEqual) //Execute topdown approach only when left and right hips are unequal
	//	{
	//		//Finding right knee from the right pelvis point
	//		q = avatar.b6;// .Inverse().mutiplication(avatar.b6);
	//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));

	//		rightKneeUpperLeg.jointPoint[0] = (rightHipSegment.jointPoint[0] + vec.mData[0] * rightKneeUpperLeg.length);
	//		rightKneeUpperLeg.jointPoint[1] = rightHipSegment.jointPoint[1] + vec.mData[2] * rightKneeUpperLeg.length;
	//		rightKneeUpperLeg.jointPoint[2] = rightHipSegment.jointPoint[2] + -vec.mData[1] * rightKneeUpperLeg.length;
	//		//cout << rightKneeUpperLeg.jointPoint[0] << "," << rightKneeUpperLeg.jointPoint[1] << "," << rightKneeUpperLeg.jointPoint[2] << ",";

	//		//Finding left knee from the left pelvis point
	//		q = avatar.b8;// .Inverse().mutiplication(avatar.b8);
	//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));

	//		leftKneeUpperLeg.jointPoint[0] = leftHipSegment.jointPoint[0] + vec.mData[0] * leftKneeUpperLeg.length;
	//		leftKneeUpperLeg.jointPoint[1] = leftHipSegment.jointPoint[1] + vec.mData[2] * leftKneeUpperLeg.length;
	//		leftKneeUpperLeg.jointPoint[2] = leftHipSegment.jointPoint[2] + -vec.mData[1] * leftKneeUpperLeg.length;
	//		//cout << leftKneeUpperLeg.jointPoint[0] << "," << leftKneeUpperLeg.jointPoint[1] << "," << leftKneeUpperLeg.jointPoint[2] << ",";

	//		//Finding right foot from the right knee point
	//		q = avatar.b7;// .Inverse().mutiplication(avatar.b7);
	//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));

	//		rightFootLowerLeg.jointPoint[0] = rightKneeUpperLeg.jointPoint[0] + vec.mData[0] * rightFootLowerLeg.length;
	//		rightFootLowerLeg.jointPoint[1] = rightKneeUpperLeg.jointPoint[1] + vec.mData[2] * rightFootLowerLeg.length;
	//		rightFootLowerLeg.jointPoint[2] = rightKneeUpperLeg.jointPoint[2] + -vec.mData[1] * rightFootLowerLeg.length;
	//		//cout << rightFootLowerLeg.jointPoint[0] << "," << rightFootLowerLeg.jointPoint[1] << "," << rightFootLowerLeg.jointPoint[2] << ",";

	//		//Finding left foot from the left knee point
	//		q = avatar.b9;// .Inverse().mutiplication(avatar.b9);
	//		vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse()));

	//		leftFootLowerLeg.jointPoint[0] = leftKneeUpperLeg.jointPoint[0] + vec.mData[0] * leftFootLowerLeg.length;
	//		leftFootLowerLeg.jointPoint[1] = leftKneeUpperLeg.jointPoint[1] + vec.mData[2] * leftFootLowerLeg.length;;
	//		leftFootLowerLeg.jointPoint[2] = leftKneeUpperLeg.jointPoint[2] + -vec.mData[1] * leftFootLowerLeg.length;
	//		//cout << leftFootLowerLeg.jointPoint[0] << "," << leftFootLowerLeg.jointPoint[1] << "," << leftFootLowerLeg.jointPoint[2] << ",";
	//	}
	//	//---------------------------------------------Updating UpperBody starting from pelvis position --------------------
	//	//Finding sternum from the pelvis point
	//	q = avatar.b0;// .Inverse().mutiplication(avatar.b0);
	//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));

	//	sternumChest.jointPoint[0] = pelvisStomach.jointPoint[0] + vec.mData[0] * pelvisStomach.length;
	//	sternumChest.jointPoint[1] = pelvisStomach.jointPoint[1] + vec.mData[2] * pelvisStomach.length;
	//	sternumChest.jointPoint[2] = pelvisStomach.jointPoint[2] + -vec.mData[1] * pelvisStomach.length;
	//	//cout << sternumChest.jointPoint[0] << "," << sternumChest.jointPoint[1] << "," << sternumChest.jointPoint[2] << ",";
	//	//Finding neck from the sternum point
	//	q = avatar.b1;// .Inverse().mutiplication(avatar.b1);
	//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));


	//	neckToChin.jointPoint[0] = sternumChest.jointPoint[0] + vec.mData[0] * sternumChest.length;
	//	neckToChin.jointPoint[1] = sternumChest.jointPoint[1] + vec.mData[2] * sternumChest.length;
	//	neckToChin.jointPoint[2] = sternumChest.jointPoint[2] + -vec.mData[1] * sternumChest.length;
	//	//cout << neckToChin.jointPoint[0] << "," << neckToChin.jointPoint[1] << "," << neckToChin.jointPoint[2] << ",";
	//	headQuat = avatar.b1; //assigning headQuat for head rotation

	//	//Finding head from the neck point
	//	q = avatar.b1;// .Inverse().mutiplication(avatar.b1);
	//	vec = q.mutiplication(quaternion{ 0,0,1,0 }.mutiplication(q.Inverse()));

	//	chinToHead.jointPoint[0] = neckToChin.jointPoint[0] + vec.mData[0] * neckToChin.length;
	//	chinToHead.jointPoint[1] = neckToChin.jointPoint[1] + vec.mData[2] * neckToChin.length;
	//	chinToHead.jointPoint[2] = neckToChin.jointPoint[2] + -vec.mData[1] * neckToChin.length;

	//	head.jointPoint[0] = chinToHead.jointPoint[0] + vec.mData[0] * chinToHead.length;
	//	head.jointPoint[1] = chinToHead.jointPoint[1] + vec.mData[2] * chinToHead.length;
	//	head.jointPoint[2] = chinToHead.jointPoint[2] + -vec.mData[1] * chinToHead.length;
	//	//cout << head.jointPoint[0] << "," << head.jointPoint[1] << "," << head.jointPoint[2] << ",";
	//	//---------------------------------------------- Hands ----------------------------------------------------
	//		//Finding rightShoulder from the neck point
	//	q = avatar.b1;// .Inverse().mutiplication(avatar.b1);
	//	vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse()));

	//	rightShoulderSegment.jointPoint[0] = neckToChin.jointPoint[0] + vec.mData[0] * rightShoulderSegment.length;
	//	rightShoulderSegment.jointPoint[1] = neckToChin.jointPoint[1] + vec.mData[2] * rightShoulderSegment.length;
	//	rightShoulderSegment.jointPoint[2] = neckToChin.jointPoint[2] + -vec.mData[1] * rightShoulderSegment.length;
	//	//cout << rightShoulderSegment.jointPoint[0] << "," << rightShoulderSegment.jointPoint[1] << "," << rightShoulderSegment.jointPoint[2] << ",";
	//	//Finding leftShoulder from the neck point
	//	q = avatar.b1;// .Inverse().mutiplication(avatar.b1);
	//	vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse()));

	//	leftShoulderSegment.jointPoint[0] = neckToChin.jointPoint[0] + vec.mData[0] * leftShoulderSegment.length;
	//	leftShoulderSegment.jointPoint[1] = neckToChin.jointPoint[1] + vec.mData[2] * leftShoulderSegment.length;
	//	leftShoulderSegment.jointPoint[2] = neckToChin.jointPoint[2] + -vec.mData[1] * leftShoulderSegment.length;
	//	//cout << leftShoulderSegment.jointPoint[0] << "," << leftShoulderSegment.jointPoint[1] << "," << leftShoulderSegment.jointPoint[2] << ",";
	//	//Finding right elbow from the right shoulder point
	//	q = avatar.b2;// .Inverse().mutiplication(avatar.b2);
	//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse())); // Attention Pose
	//	//vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse())); // T-Pose

	//	rightElbowUpperArm.jointPoint[0] = rightShoulderSegment.jointPoint[0] + vec.mData[0] * rightElbowUpperArm.length;
	//	rightElbowUpperArm.jointPoint[1] = rightShoulderSegment.jointPoint[1] + vec.mData[2] * rightElbowUpperArm.length;
	//	rightElbowUpperArm.jointPoint[2] = rightShoulderSegment.jointPoint[2] + -vec.mData[1] * rightElbowUpperArm.length;
	//	//cout << rightElbowUpperArm.jointPoint[0] << "," << rightElbowUpperArm.jointPoint[1] << "," << rightElbowUpperArm.jointPoint[2] << ",";
	//	//Finding left elbow from the left shoulder point
	//	q = avatar.b4;// .Inverse().mutiplication(avatar.b4);
	//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse())); // Attention Pose
	//	//vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse())); // T-Pose

	//	leftElbowUpperArm.jointPoint[0] = leftShoulderSegment.jointPoint[0] + vec.mData[0] * leftElbowUpperArm.length;
	//	leftElbowUpperArm.jointPoint[1] = leftShoulderSegment.jointPoint[1] + vec.mData[2] * leftElbowUpperArm.length;
	//	leftElbowUpperArm.jointPoint[2] = leftShoulderSegment.jointPoint[2] + -vec.mData[1] * leftElbowUpperArm.length;
	//	//cout << leftElbowUpperArm.jointPoint[0] << "," << leftElbowUpperArm.jointPoint[1] << "," << leftElbowUpperArm.jointPoint[2] << ",";
	//	//Finding right hand from the right elbow point
	//	q = avatar.b3;// .Inverse().mutiplication(avatar.b3);
	//	rightHand.rotation = q;
	//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse())); // Attention pose
	//	//vec = q.mutiplication(quaternion{ -1,0,0,0 }.mutiplication(q.Inverse())); // t-Pose

	//	rightHandLowerArm.jointPoint[0] = rightElbowUpperArm.jointPoint[0] + vec.mData[0] * rightHandLowerArm.length;
	//	rightHandLowerArm.jointPoint[1] = rightElbowUpperArm.jointPoint[1] + vec.mData[2] * rightHandLowerArm.length;
	//	rightHandLowerArm.jointPoint[2] = rightElbowUpperArm.jointPoint[2] + -vec.mData[1] * rightHandLowerArm.length;
	//	//cout << rightHandLowerArm.jointPoint[0] << "," << rightHandLowerArm.jointPoint[1] << "," << rightHandLowerArm.jointPoint[2]<<",";
	//	//Finding left hand from the left elbow point
	//	q = avatar.b5;// .Inverse().mutiplication(avatar.b5);
	//	leftHand.rotation = q;
	//	vec = q.mutiplication(quaternion{ 0,0,-1,0 }.mutiplication(q.Inverse())); // Attention Pose
	//	//vec = q.mutiplication(quaternion{ 1,0,0,0 }.mutiplication(q.Inverse())); // T-pose

	//	leftHandLowerArm.jointPoint[0] = leftElbowUpperArm.jointPoint[0] + vec.mData[0] * leftHandLowerArm.length;
	//	leftHandLowerArm.jointPoint[1] = leftElbowUpperArm.jointPoint[1] + vec.mData[2] * leftHandLowerArm.length;
	//	leftHandLowerArm.jointPoint[2] = leftElbowUpperArm.jointPoint[2] + -vec.mData[1] * leftHandLowerArm.length;

