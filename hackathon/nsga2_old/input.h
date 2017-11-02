/*This is a file to get the input for the GA program*/

void input(FILE *rep_ptr);

void input(FILE *rep_ptr)
{
	int i;
	float r;
	float cc;
	int rest_i=0;
	int rest_j=0;
	int rest_k=0;
	int rest_flag=1;

	nvar = 30;
	nchrom = 0;
	if (!strcmp(prob,"ZDT4")||!strcmp(prob,"ZDT6"))
		nvar = 10;
	else
		if (!strcmp(prob,"PTTS")||!strcmp(prob,"PTTS2")||!strcmp(prob,"PTTS40"))
			nvar = task_num;

	nfunc = 2;
	ncons = 0;
	fflush(stdin);//刷新标准输入缓冲区，把输入缓冲区里的东西丢弃

	popsize = 100;	
	if (!strcmp(prob,"PTTS"))
		popsize = 20;//大修前20*8时70,6*8时10。
	if (!strcmp(prob,"PTTS2"))
		popsize = 80;
	if (!strcmp(prob,"PTTS40"))
		popsize = 100;

	gener = 250;
	if (!strcmp(prob,"ZDT4")||!strcmp(prob,"ZDT6"))
		gener = 150;
	if (!strcmp(prob,"PTTS"))
		gener = 20;//大修前20*8时120,6*8时20。
	if (!strcmp(prob,"PTTS2"))
		gener = 70;	
	if (!strcmp(prob,"PTTS40"))
		gener = 100;	

	//printf("Give the cross-over probability (between 0.5 and 1)\n");
	//scanf("%f",&pcross);
	pcross = 0.9;

	if (nvar > 0) 
	{
		cc = 1.0/nvar;
		//printf("Give the mutation probability for real-coded vectors (between 0 and %f)\n",cc);
		//scanf("%f",&pmut_r);
		pmut_r = cc;

		/*Asks for Distribution Index for Cross-over (Default = 20)*/
		/*For Mutation (Default = 10 to 500)*/

		//printf("Give Distribution Index for real-coded crossover between 0.5 to 100\n");
		//scanf("%f",&di);
		di = 20;

		//printf("Give Distribution Index for real-coded mutation between 0.5 to 500\n");
		//scanf("%f",&dim);
		dim = 20;

		for(i = 0; i < nvar; i++)
		{
			/*Specify the limits of the variables*/

			//printf("Give Lower & Upper limits of the %dth real-coded variable\n",i+1);
			//scanf("%f %f",&lim_r[i][0],&lim_r[i][1]);
			lim_r[i][0] = 0;
			lim_r[i][1] = 1;
		}
		if (!strcmp(prob,"ZDT4"))
		{
			for (i = 1; i < nvar; i++)
			{
				lim_r[i][0] = -5;
				lim_r[i][1] = 5;
			}
		}

		//printf("If limits on real-coded variable are rigid (1 if yes)\n");
		//scanf("%d",&ans);
		ans = 1;
	}

	chrom = 0;
	if (nchrom > 0)
	{
		/*Asking for Crossover Type*/
		//printf("Give Crossover type 1 for Simple one & 2 for Uniform X-over\n");
		//scanf("%d",&optype);
		optype = 1;
		/*Specify the Cross-over Probability for the Simple or Real Coded
		Cross-over suited Range is 0.9 to 0.99*/

		for (i = 0; i < nchrom; i++)
		{
			/*For Binary Coded Problem
			Specify the no of bits for each variable
			Total Sum of the bit value must be equal to
			chromosome length*/
			/*printf("Give the no.of bits assigned to the %d variable\n",i+1);
			scanf("%d",&vlen[i]);*/
			vlen[i] = 1;
			chrom += vlen[i];

			//printf("Give lower & the upper limits of the %d variable\n",i+1);
			//scanf("%f %f",&lim_b[i][0],&lim_b[i][1]);
			lim_b[i][0] = 0;
			lim_b[i][1] = 1;
		}
		//if(chrom > maxchrom)
		//{
		//	printf("Increase chromosome size. Currently set %d.\n",maxchrom);
		//	exit(1);
		//}

		/* Ask for mutation probablity */
		cc = 1.0/chrom;

		//printf("Give the mutation probability for binary strings (between 0 and %f)\n",cc);
		//scanf("%f",&pmut_b);
		pmut_b = cc;

	}

	//printf("----------------------------------------------------------------\n");

	/*Give the initial seed*/
	//printf("\nGive random seed(between 0 and 1)\n");
	//scanf("%f",&seed);
	//seed = 0.1;
	r = rand();
	seed = (r+1)/32768;

	// end of reading parameters


	/*Print the GA parameters and problem parameters 
	in the file output.dat*/

	//fprintf(rep_ptr,"GA PARAMETERS\n");
	//fprintf(rep_ptr,"-------------------------------------------------------\n");

	//fprintf(rep_ptr,"Population Size ->%d\n",popsize);

	//fprintf(rep_ptr,"Chromosome Length ->%d\n",chrom);

	//fprintf(rep_ptr,"No. of generations ->%d\n",gener);

	//fprintf(rep_ptr,"No. of Functions ->%d\n",nfunc);

	//fprintf(rep_ptr,"No. of Constraints ->%d\n",ncons);

	//if (nchrom > 0)
	//	fprintf(rep_ptr,"No. of binary-coded variables ->%d\n",nchrom);
	//if (nvar > 0) 
	//	fprintf(rep_ptr,"No. of real-coded variables ->%d\n",nvar);

	//fprintf(rep_ptr,"Selection Strategy is Tournament Selection\n");

	//for(i = 0;i < nchrom;i++)
	//{

	//	fprintf(rep_ptr,"Binary-coded variable No.-> %d\n",i);

	//	fprintf(rep_ptr,"No. of bits assigned to it ->%d\n",vlen[i]);

	//	fprintf(rep_ptr,"Lower limits on %dth variable-> %f\n",i,lim_b[i][0]);

	//	fprintf(rep_ptr,"Upper limits on %dth variable ->%f\n",i,lim_b[i][1]);
	//}

	//for(i = 0; i < nvar; i++)
	//{

	//	fprintf(rep_ptr,"Real-coded variable No.-> %d\n",i);

	//	fprintf(rep_ptr,"Lower limits on %dth variable-> %f\n",i,lim_r[i][0]);

	//	fprintf(rep_ptr,"Upper limits on %dth variable ->%f\n",i,lim_r[i][1]);
	//	if (ans == 1)
	//		fprintf(rep_ptr,"Variable bounds are rigid\n");
	//	else 
	//		fprintf(rep_ptr,"Variable bounds are not rigid\n");
	//}

	//if (nchrom > 0)
	//{  
	//	if(optype == 1)
	//		fprintf(rep_ptr,"X-over on binary string is SINGLE POINT X-OVER\n");

	//	if (optype ==2)
	//		fprintf(rep_ptr,"X-over on binary strings is UNIFORM X-OVER \n");
	//}
	//if (nvar > 0) 
	//	fprintf(rep_ptr,"Crossover parameter in the SBX operator is %f\n",di);

	//fprintf(rep_ptr,"Cross-over Probability ->%f\n",pcross);

	//if (nchrom > 0)
	//	fprintf(rep_ptr,"Mutation Probability for binary strings -> %f\n",pmut_b);

	//if (nvar > 0)
	//	fprintf(rep_ptr,"Mutation Probability for real-coded vectors -> %f\n",pmut_r);

	//fprintf(rep_ptr,"Random Seed ->%f\n",seed);

	if (!strcmp(prob,"PTTS"))
	{
		/***********************方案***********************/
		meth[1].m[1] = 1;  meth[1].m[2] = 2;  meth[1].m[3] = 3;  meth[1].m[4] = 0;  meth[1].m[5] = 0;

		meth[2].m[1] = 1;  meth[2].m[2] = 2;  meth[2].m[3] = 3;  meth[2].m[4] = 4;  meth[2].m[5] = 0;

		meth[3].m[1] = 1;  meth[3].m[2] = 2;  meth[3].m[3] = 0;  meth[3].m[4] = 0;  meth[3].m[5] = 0;

		meth[4].m[1] = 1;  meth[4].m[2] = 2;  meth[4].m[3] = 0;  meth[4].m[4] = 0;  meth[4].m[5] = 0;

		meth[5].m[1] = 1;  meth[5].m[2] = 0;  meth[5].m[3] = 0;  meth[5].m[4] = 0;  meth[5].m[5] = 0;

		meth[6].m[1] = 1;  meth[6].m[2] = 2;  meth[6].m[3] = 3;  meth[6].m[4] = 0;  meth[6].m[5] = 0;

		meth[7].m[1] = 1;  meth[7].m[2] = 2;  meth[7].m[3] = 3;  meth[7].m[4] = 0;  meth[7].m[5] = 0;

		meth[8].m[1] = 1;  meth[8].m[2] = 2;  meth[8].m[3] = 3;  meth[8].m[4] = 0;  meth[8].m[5] = 0;

		meth[9].m[1] = 1;  meth[9].m[2] = 2;  meth[9].m[3] = 3;  meth[9].m[4] = 0;  meth[9].m[5] = 0;

		meth[10].m[1] = 1;  meth[10].m[2] = 2;  meth[10].m[3] = 3;  meth[10].m[4] = 0;  meth[10].m[5] = 0;

		meth[11].m[1] = 1;  meth[11].m[2] = 2;  meth[11].m[3] = 3;  meth[11].m[4] = 0;  meth[11].m[5] = 0;

		meth[12].m[1] = 1;  meth[12].m[2] = 2;  meth[12].m[3] = 3;  meth[12].m[4] = 0;  meth[12].m[5] = 0;

		meth[13].m[1] = 1;  meth[13].m[2] = 2;  meth[13].m[3] = 3;  meth[13].m[4] = 0;  meth[13].m[5] = 0;

		meth[14].m[1] = 1;  meth[14].m[2] = 2;  meth[14].m[3] = 3;  meth[14].m[4] = 0;  meth[14].m[5] = 0;

		meth[15].m[1] = 1;  meth[15].m[2] = 0;  meth[15].m[3] = 0;  meth[15].m[4] = 0;  meth[15].m[5] = 0;

		meth[16].m[1] = 1;  meth[16].m[2] = 2;  meth[16].m[3] = 3;  meth[16].m[4] = 0;  meth[16].m[5] = 0;

		meth[17].m[1] = 1;  meth[17].m[2] = 2;  meth[17].m[3] = 3;  meth[17].m[4] = 0;  meth[17].m[5] = 0;

		meth[18].m[1] = 1;  meth[18].m[2] = 0;  meth[18].m[3] = 0;  meth[18].m[4] = 0;  meth[18].m[5] = 0;

		meth[19].m[1] = 1;  meth[19].m[2] = 2;  meth[19].m[3] = 3;  meth[19].m[4] = 4;  meth[19].m[5] = 0;

		meth[20].m[1] = 1;  meth[20].m[2] = 2;  meth[20].m[3] = 3;  meth[20].m[4] = 0;  meth[20].m[5] = 0;

		/***********************资源***********************/
		meth[1].r[1][1] = 1;  meth[1].r[1][2] = 4;  meth[1].r[1][3] = 0;
		meth[1].r[2][1] = 3;  meth[1].r[2][2] = 5;  meth[1].r[2][3] = 0;
		meth[1].r[3][1] = 6;  meth[1].r[3][2] = 8;  meth[1].r[3][3] = 0;
		meth[1].r[4][1] = 0;  meth[1].r[4][2] = 0;  meth[1].r[4][3] = 0;
		meth[1].r[5][1] = 0;  meth[1].r[5][2] = 0;  meth[1].r[5][3] = 0;

		meth[2].r[1][1] = 2;  meth[2].r[1][2] = 0;  meth[2].r[1][3] = 0;
		meth[2].r[2][1] = 4;  meth[2].r[2][2] = 0;  meth[2].r[2][3] = 0;
		meth[2].r[3][1] = 6;  meth[2].r[3][2] = 0;  meth[2].r[3][3] = 0;
		meth[2].r[4][1] = 7;  meth[2].r[4][2] = 0;  meth[2].r[4][3] = 0;
		meth[2].r[5][1] = 0;  meth[2].r[5][2] = 0;  meth[2].r[5][3] = 0;

		meth[3].r[1][1] = 3;  meth[3].r[1][2] = 0;  meth[3].r[1][3] = 0;
		meth[3].r[2][1] = 5;  meth[3].r[2][2] = 0;  meth[3].r[2][3] = 0;
		meth[3].r[3][1] = 0;  meth[3].r[3][2] = 0;  meth[3].r[3][3] = 0;
		meth[3].r[4][1] = 0;  meth[3].r[4][2] = 0;  meth[3].r[4][3] = 0;
		meth[3].r[5][1] = 0;  meth[3].r[5][2] = 0;  meth[3].r[5][3] = 0;

		meth[4].r[1][1] = 4;  meth[4].r[1][2] = 0;  meth[4].r[1][3] = 0;
		meth[4].r[2][1] = 8;  meth[4].r[2][2] = 0;  meth[4].r[2][3] = 0;
		meth[4].r[3][1] = 0;  meth[4].r[3][2] = 0;  meth[4].r[3][3] = 0;
		meth[4].r[4][1] = 0;  meth[4].r[4][2] = 0;  meth[4].r[4][3] = 0;
		meth[4].r[5][1] = 0;  meth[4].r[5][2] = 0;  meth[4].r[5][3] = 0;

		meth[5].r[1][1] = 7;  meth[5].r[1][2] = 0;  meth[5].r[1][3] = 0;
		meth[5].r[2][1] = 0;  meth[5].r[2][2] = 0;  meth[5].r[2][3] = 0;
		meth[5].r[3][1] = 0;  meth[5].r[3][2] = 0;  meth[5].r[3][3] = 0;
		meth[5].r[4][1] = 0;  meth[5].r[4][2] = 0;  meth[5].r[4][3] = 0;
		meth[5].r[5][1] = 0;  meth[5].r[5][2] = 0;  meth[5].r[5][3] = 0;

		meth[6].r[1][1] = 1;  meth[6].r[1][2] = 4;  meth[6].r[1][3] = 0;
		meth[6].r[2][1] = 3;  meth[6].r[2][2] = 7;  meth[6].r[2][3] = 0;
		meth[6].r[3][1] = 6;  meth[6].r[3][2] = 8;  meth[6].r[3][3] = 0;
		meth[6].r[4][1] = 0;  meth[6].r[4][2] = 0;  meth[6].r[4][3] = 0;
		meth[6].r[5][1] = 0;  meth[6].r[5][2] = 0;  meth[6].r[5][3] = 0;

		meth[7].r[1][1] = 1;  meth[7].r[1][2] = 2;  meth[7].r[1][3] = 0;
		meth[7].r[2][1] = 1;  meth[7].r[2][2] = 7;  meth[7].r[2][3] = 0;
		meth[7].r[3][1] = 3;  meth[7].r[3][2] = 8;  meth[7].r[3][3] = 0;
		meth[7].r[4][1] = 0;  meth[7].r[4][2] = 0;  meth[7].r[4][3] = 0;
		meth[7].r[5][1] = 0;  meth[7].r[5][2] = 0;  meth[7].r[5][3] = 0;

		meth[8].r[1][1] = 1;  meth[8].r[1][2] = 3;  meth[8].r[1][3] = 0;
		meth[8].r[2][1] = 1;  meth[8].r[2][2] = 5;  meth[8].r[2][3] = 0;
		meth[8].r[3][1] = 4;  meth[8].r[3][2] = 7;  meth[8].r[3][3] = 0;
		meth[8].r[4][1] = 0;  meth[8].r[4][2] = 0;  meth[8].r[4][3] = 0;
		meth[8].r[5][1] = 0;  meth[8].r[5][2] = 0;  meth[8].r[5][3] = 0;

		meth[9].r[1][1] = 1;  meth[9].r[1][2] = 4;  meth[9].r[1][3] = 0;
		meth[9].r[2][1] = 3;  meth[9].r[2][2] = 4;  meth[9].r[2][3] = 0;
		meth[9].r[3][1] = 7;  meth[9].r[3][2] = 8;  meth[9].r[3][3] = 0;
		meth[9].r[4][1] = 0;  meth[9].r[4][2] = 0;  meth[9].r[4][3] = 0;
		meth[9].r[5][1] = 0;  meth[9].r[5][2] = 0;  meth[9].r[5][3] = 0;

		meth[10].r[1][1] = 1;  meth[10].r[1][2] = 0;  meth[10].r[1][3] = 0;
		meth[10].r[2][1] = 4;  meth[10].r[2][2] = 0;  meth[10].r[2][3] = 0;
		meth[10].r[3][1] = 8;  meth[10].r[3][2] = 0;  meth[10].r[3][3] = 0;
		meth[10].r[4][1] = 0;  meth[10].r[4][2] = 0;  meth[10].r[4][3] = 0;
		meth[10].r[5][1] = 0;  meth[10].r[5][2] = 0;  meth[10].r[5][3] = 0;

		meth[11].r[1][1] = 2;  meth[11].r[1][2] = 3;  meth[11].r[1][3] = 0;
		meth[11].r[2][1] = 2;  meth[11].r[2][2] = 5;  meth[11].r[2][3] = 0;
		meth[11].r[3][1] = 6;  meth[11].r[3][2] = 7;  meth[11].r[3][3] = 0;
		meth[11].r[4][1] = 0;  meth[11].r[4][2] = 0;  meth[11].r[4][3] = 0;
		meth[11].r[5][1] = 0;  meth[11].r[5][2] = 0;  meth[11].r[5][3] = 0;

		meth[12].r[1][1] = 2;  meth[12].r[1][2] = 0;  meth[12].r[1][3] = 0;
		meth[12].r[2][1] = 5;  meth[12].r[2][2] = 0;  meth[12].r[2][3] = 0;
		meth[12].r[3][1] = 6;  meth[12].r[3][2] = 0;  meth[12].r[3][3] = 0;
		meth[12].r[4][1] = 0;  meth[12].r[4][2] = 0;  meth[12].r[4][3] = 0;
		meth[12].r[5][1] = 0;  meth[12].r[5][2] = 0;  meth[12].r[5][3] = 0;

		meth[13].r[1][1] = 2;  meth[13].r[1][2] = 0;  meth[13].r[1][3] = 0;
		meth[13].r[2][1] = 6;  meth[13].r[2][2] = 0;  meth[13].r[2][3] = 0;
		meth[13].r[3][1] = 8;  meth[13].r[3][2] = 0;  meth[13].r[3][3] = 0;
		meth[13].r[4][1] = 0;  meth[13].r[4][2] = 0;  meth[13].r[4][3] = 0;
		meth[13].r[5][1] = 0;  meth[13].r[5][2] = 0;  meth[13].r[5][3] = 0;

		meth[14].r[1][1] = 3;  meth[14].r[1][2] = 0;  meth[14].r[1][3] = 0;
		meth[14].r[2][1] = 5;  meth[14].r[2][2] = 0;  meth[14].r[2][3] = 0;
		meth[14].r[3][1] = 7;  meth[14].r[3][2] = 0;  meth[14].r[3][3] = 0;
		meth[14].r[4][1] = 0;  meth[14].r[4][2] = 0;  meth[14].r[4][3] = 0;
		meth[14].r[5][1] = 0;  meth[14].r[5][2] = 0;  meth[14].r[5][3] = 0;

		meth[15].r[1][1] = 8;  meth[15].r[1][2] = 0;  meth[15].r[1][3] = 0;
		meth[15].r[2][1] = 0;  meth[15].r[2][2] = 0;  meth[15].r[2][3] = 0;
		meth[15].r[3][1] = 0;  meth[15].r[3][2] = 0;  meth[15].r[3][3] = 0;
		meth[15].r[4][1] = 0;  meth[15].r[4][2] = 0;  meth[15].r[4][3] = 0;
		meth[15].r[5][1] = 0;  meth[15].r[5][2] = 0;  meth[15].r[5][3] = 0;

		meth[16].r[1][1] = 2;  meth[16].r[1][2] = 0;  meth[16].r[1][3] = 0;
		meth[16].r[2][1] = 5;  meth[16].r[2][2] = 0;  meth[16].r[2][3] = 0;
		meth[16].r[3][1] = 8;  meth[16].r[3][2] = 0;  meth[16].r[3][3] = 0;
		meth[16].r[4][1] = 0;  meth[16].r[4][2] = 0;  meth[16].r[4][3] = 0;
		meth[16].r[5][1] = 0;  meth[16].r[5][2] = 0;  meth[16].r[5][3] = 0;

		meth[17].r[1][1] = 1;  meth[17].r[1][2] = 2;  meth[17].r[1][3] = 0;
		meth[17].r[2][1] = 5;  meth[17].r[2][2] = 7;  meth[17].r[2][3] = 0;
		meth[17].r[3][1] = 5;  meth[17].r[3][2] = 8;  meth[17].r[3][3] = 0;
		meth[17].r[4][1] = 0;  meth[17].r[4][2] = 0;  meth[17].r[4][3] = 0;
		meth[17].r[5][1] = 0;  meth[17].r[5][2] = 0;  meth[17].r[5][3] = 0;

		meth[18].r[1][1] = 6;  meth[18].r[1][2] = 0;  meth[18].r[1][3] = 0;
		meth[18].r[2][1] = 0;  meth[18].r[2][2] = 0;  meth[18].r[2][3] = 0;
		meth[18].r[3][1] = 0;  meth[18].r[3][2] = 0;  meth[18].r[3][3] = 0;
		meth[18].r[4][1] = 0;  meth[18].r[4][2] = 0;  meth[18].r[4][3] = 0;
		meth[18].r[5][1] = 0;  meth[18].r[5][2] = 0;  meth[18].r[5][3] = 0;

		meth[19].r[1][1] = 2;  meth[19].r[1][2] = 0;  meth[19].r[1][3] = 0;
		meth[19].r[2][1] = 4;  meth[19].r[2][2] = 0;  meth[19].r[2][3] = 0;
		meth[19].r[3][1] = 5;  meth[19].r[3][2] = 0;  meth[19].r[3][3] = 0;
		meth[19].r[4][1] = 8;  meth[19].r[4][2] = 0;  meth[19].r[4][3] = 0;
		meth[19].r[5][1] = 0;  meth[19].r[5][2] = 0;  meth[19].r[5][3] = 0;

		meth[20].r[1][1] = 3;  meth[20].r[1][2] = 0;  meth[20].r[1][3] = 0;
		meth[20].r[2][1] = 6;  meth[20].r[2][2] = 0;  meth[20].r[2][3] = 0;
		meth[20].r[3][1] = 8;  meth[20].r[3][2] = 0;  meth[20].r[3][3] = 0;
		meth[20].r[4][1] = 0;  meth[20].r[4][2] = 0;  meth[20].r[4][3] = 0;
		meth[20].r[5][1] = 0;  meth[20].r[5][2] = 0;  meth[20].r[5][3] = 0;

		/***********************时间***********************/
		meth[1].time[1] = 2;  meth[1].time[2] = 5;  meth[1].time[3] = 3;  meth[1].time[4] = 0;  meth[1].time[5] = 0;

		meth[2].time[1] = 3;  meth[2].time[2] = 4;  meth[2].time[3] = 3;  meth[2].time[4] = 4;  meth[2].time[5] = 0;

		meth[3].time[1] = 5;  meth[3].time[2] = 5;  meth[3].time[3] = 0;  meth[3].time[4] = 0;  meth[3].time[5] = 0;

		meth[4].time[1] = 22;  meth[4].time[2] = 20;  meth[4].time[3] = 0;  meth[4].time[4] = 0;  meth[4].time[5] = 0;

		meth[5].time[1] = 23;  meth[5].time[2] = 0;  meth[5].time[3] = 0;  meth[5].time[4] = 0;  meth[5].time[5] = 0;

		meth[6].time[1] = 7;  meth[6].time[2] = 8;  meth[6].time[3] = 8;  meth[6].time[4] = 0;  meth[6].time[5] = 0;

		meth[7].time[1] = 2;  meth[7].time[2] = 2;  meth[7].time[3] = 3;  meth[7].time[4] = 0;  meth[7].time[5] = 0;

		meth[8].time[1] = 5;  meth[8].time[2] = 4;  meth[8].time[3] = 2;  meth[8].time[4] = 0;  meth[8].time[5] = 0;

		meth[9].time[1] = 11;  meth[9].time[2] = 13;  meth[9].time[3] = 12;  meth[9].time[4] = 0;  meth[9].time[5] = 0;

		meth[10].time[1] = 9;  meth[10].time[2] = 10;  meth[10].time[3] = 10;  meth[10].time[4] = 0;  meth[10].time[5] = 0;

		meth[11].time[1] = 6;  meth[11].time[2] = 8;  meth[11].time[3] = 8;  meth[11].time[4] = 0;  meth[11].time[5] = 0;

		meth[12].time[1] = 11;  meth[12].time[2] = 13;  meth[12].time[3] = 13;  meth[12].time[4] = 0;  meth[12].time[5] = 0;

		meth[13].time[1] = 4;  meth[13].time[2] = 5;  meth[13].time[3] = 4;  meth[13].time[4] = 0;  meth[13].time[5] = 0;

		meth[14].time[1] = 7;  meth[14].time[2] = 8;  meth[14].time[3] = 8;  meth[14].time[4] = 0;  meth[14].time[5] = 0;

		meth[15].time[1] = 2;  meth[15].time[2] = 0;  meth[15].time[3] = 0;  meth[15].time[4] = 0;  meth[15].time[5] = 0;

		meth[16].time[1] = 9;  meth[16].time[2] = 7;  meth[16].time[3] = 6;  meth[16].time[4] = 0;  meth[16].time[5] = 0;

		meth[17].time[1] = 10;  meth[17].time[2] = 12;  meth[17].time[3] = 11;  meth[17].time[4] = 0;  meth[17].time[5] = 0;

		meth[18].time[1] = 15;  meth[18].time[2] = 0;  meth[18].time[3] = 0;  meth[18].time[4] = 0;  meth[18].time[5] = 0;

		meth[19].time[1] = 8;  meth[19].time[2] = 7;  meth[19].time[3] = 7;  meth[19].time[4] = 6;  meth[19].time[5] = 0;

		meth[20].time[1] = 4;  meth[20].time[2] = 4;  meth[20].time[3] = 5;  meth[20].time[4] = 0;  meth[20].time[5] = 0;
	}
	else
		if (!strcmp(prob,"PTTS2"))
		{
			/***********************方案***********************/
			meth[1].m[1] = 1;  meth[1].m[2] = 0;  meth[1].m[3] = 0;  meth[1].m[4] = 0;  meth[1].m[5] = 0;

			meth[2].m[1] = 1;  meth[2].m[2] = 0;  meth[2].m[3] = 0;  meth[2].m[4] = 0;  meth[2].m[5] = 0;

			meth[3].m[1] = 1;  meth[3].m[2] = 0;  meth[3].m[3] = 0;  meth[3].m[4] = 0;  meth[3].m[5] = 0;

			meth[4].m[1] = 1;  meth[4].m[2] = 0;  meth[4].m[3] = 0;  meth[4].m[4] = 0;  meth[4].m[5] = 0;

			meth[5].m[1] = 1;  meth[5].m[2] = 0;  meth[5].m[3] = 0;  meth[5].m[4] = 0;  meth[5].m[5] = 0;

			meth[6].m[1] = 1;  meth[6].m[2] = 0;  meth[6].m[3] = 0;  meth[6].m[4] = 0;  meth[6].m[5] = 0;

			meth[7].m[1] = 1;  meth[7].m[2] = 0;  meth[7].m[3] = 0;  meth[7].m[4] = 0;  meth[7].m[5] = 0;

			meth[8].m[1] = 1;  meth[8].m[2] = 0;  meth[8].m[3] = 0;  meth[8].m[4] = 0;  meth[8].m[5] = 0;

			meth[9].m[1] = 1;  meth[9].m[2] = 0;  meth[9].m[3] = 0;  meth[9].m[4] = 0;  meth[9].m[5] = 0;

			meth[10].m[1] = 1;  meth[10].m[2] = 0;  meth[10].m[3] = 0;  meth[10].m[4] = 0;  meth[10].m[5] = 0;

			meth[11].m[1] = 1;  meth[11].m[2] = 0;  meth[11].m[3] = 0;  meth[11].m[4] = 0;  meth[11].m[5] = 0;

			meth[12].m[1] = 1;  meth[12].m[2] = 0;  meth[12].m[3] = 0;  meth[12].m[4] = 0;  meth[12].m[5] = 0;

			meth[13].m[1] = 1;  meth[13].m[2] = 0;  meth[13].m[3] = 0;  meth[13].m[4] = 0;  meth[13].m[5] = 0;

			meth[14].m[1] = 1;  meth[14].m[2] = 0;  meth[14].m[3] = 0;  meth[14].m[4] = 0;  meth[14].m[5] = 0;

			meth[15].m[1] = 1;  meth[15].m[2] = 0;  meth[15].m[3] = 0;  meth[15].m[4] = 0;  meth[15].m[5] = 0;
			//-----------------------------------------------------------------------------------

			meth[16].m[1] = 1;  meth[16].m[2] = 0;  meth[16].m[3] = 0;  meth[16].m[4] = 0;  meth[16].m[5] = 0;

			meth[17].m[1] = 1;  meth[17].m[2] = 0;  meth[17].m[3] = 0;  meth[17].m[4] = 0;  meth[17].m[5] = 0;

			meth[18].m[1] = 1;  meth[18].m[2] = 0;  meth[18].m[3] = 0;  meth[18].m[4] = 0;  meth[18].m[5] = 0;

			meth[19].m[1] = 1;  meth[19].m[2] = 0;  meth[19].m[3] = 0;  meth[19].m[4] = 0;  meth[19].m[5] = 0;

			meth[20].m[1] = 1;  meth[20].m[2] = 0;  meth[20].m[3] = 0;  meth[20].m[4] = 0;  meth[20].m[5] = 0;

			meth[21].m[1] = 1;  meth[21].m[2] = 0;  meth[21].m[3] = 0;  meth[21].m[4] = 0;  meth[21].m[5] = 0;

			meth[22].m[1] = 1;  meth[22].m[2] = 0;  meth[22].m[3] = 0;  meth[22].m[4] = 0;  meth[22].m[5] = 0;

			meth[23].m[1] = 1;  meth[23].m[2] = 0;  meth[23].m[3] = 0;  meth[23].m[4] = 0;  meth[23].m[5] = 0;

			meth[24].m[1] = 1;  meth[24].m[2] = 0;  meth[24].m[3] = 0;  meth[24].m[4] = 0;  meth[24].m[5] = 0;

			meth[25].m[1] = 1;  meth[25].m[2] = 0;  meth[25].m[3] = 0;  meth[25].m[4] = 0;  meth[25].m[5] = 0;

			meth[26].m[1] = 1;  meth[26].m[2] = 0;  meth[26].m[3] = 0;  meth[26].m[4] = 0;  meth[26].m[5] = 0;

			meth[27].m[1] = 1;  meth[27].m[2] = 0;  meth[27].m[3] = 0;  meth[27].m[4] = 0;  meth[27].m[5] = 0;

			meth[28].m[1] = 1;  meth[28].m[2] = 0;  meth[28].m[3] = 0;  meth[28].m[4] = 0;  meth[28].m[5] = 0;

			meth[29].m[1] = 1;  meth[29].m[2] = 0;  meth[29].m[3] = 0;  meth[29].m[4] = 0;  meth[29].m[5] = 0;

			meth[30].m[1] = 1;  meth[30].m[2] = 0;  meth[30].m[3] = 0;  meth[30].m[4] = 0;  meth[30].m[5] = 0;


			/***********************资源***********************/
			meth[1].r[1][1] = 1;  meth[1].r[1][2] = 3;  meth[1].r[1][3] = 0;
			meth[1].r[2][1] = 0;  meth[1].r[2][2] = 0;  meth[1].r[2][3] = 0;
			meth[1].r[3][1] = 0;  meth[1].r[3][2] = 0;  meth[1].r[3][3] = 0;
			meth[1].r[4][1] = 0;  meth[1].r[4][2] = 0;  meth[1].r[4][3] = 0;
			meth[1].r[5][1] = 0;  meth[1].r[5][2] = 0;  meth[1].r[5][3] = 0;

			meth[2].r[1][1] = 1;  meth[2].r[1][2] = 5;  meth[2].r[1][3] = 0;
			meth[2].r[2][1] = 0;  meth[2].r[2][2] = 0;  meth[2].r[2][3] = 0;
			meth[2].r[3][1] = 0;  meth[2].r[3][2] = 0;  meth[2].r[3][3] = 0;
			meth[2].r[4][1] = 0;  meth[2].r[4][2] = 0;  meth[2].r[4][3] = 0;
			meth[2].r[5][1] = 0;  meth[2].r[5][2] = 0;  meth[2].r[5][3] = 0;

			meth[3].r[1][1] = 6;  meth[3].r[1][2] = 0;  meth[3].r[1][3] = 0;
			meth[3].r[2][1] = 0;  meth[3].r[2][2] = 0;  meth[3].r[2][3] = 0;
			meth[3].r[3][1] = 0;  meth[3].r[3][2] = 0;  meth[3].r[3][3] = 0;
			meth[3].r[4][1] = 0;  meth[3].r[4][2] = 0;  meth[3].r[4][3] = 0;
			meth[3].r[5][1] = 0;  meth[3].r[5][2] = 0;  meth[3].r[5][3] = 0;

			meth[4].r[1][1] = 1;  meth[4].r[1][2] = 6;  meth[4].r[1][3] = 0;
			meth[4].r[2][1] = 0;  meth[4].r[2][2] = 0;  meth[4].r[2][3] = 0;
			meth[4].r[3][1] = 0;  meth[4].r[3][2] = 0;  meth[4].r[3][3] = 0;
			meth[4].r[4][1] = 0;  meth[4].r[4][2] = 0;  meth[4].r[4][3] = 0;
			meth[4].r[5][1] = 0;  meth[4].r[5][2] = 0;  meth[4].r[5][3] = 0;

			meth[5].r[1][1] = 2;  meth[5].r[1][2] = 7;  meth[5].r[1][3] = 0;
			meth[5].r[2][1] = 0;  meth[5].r[2][2] = 0;  meth[5].r[2][3] = 0;
			meth[5].r[3][1] = 0;  meth[5].r[3][2] = 0;  meth[5].r[3][3] = 0;
			meth[5].r[4][1] = 0;  meth[5].r[4][2] = 0;  meth[5].r[4][3] = 0;
			meth[5].r[5][1] = 0;  meth[5].r[5][2] = 0;  meth[5].r[5][3] = 0;

			meth[6].r[1][1] = 2;  meth[6].r[1][2] = 3;  meth[6].r[1][3] = 0;
			meth[6].r[2][1] = 0;  meth[6].r[2][2] = 0;  meth[6].r[2][3] = 0;
			meth[6].r[3][1] = 0;  meth[6].r[3][2] = 0;  meth[6].r[3][3] = 0;
			meth[6].r[4][1] = 0;  meth[6].r[4][2] = 0;  meth[6].r[4][3] = 0;
			meth[6].r[5][1] = 0;  meth[6].r[5][2] = 0;  meth[6].r[5][3] = 0;

			meth[7].r[1][1] = 2;  meth[7].r[1][2] = 4;  meth[7].r[1][3] = 0;
			meth[7].r[2][1] = 0;  meth[7].r[2][2] = 0;  meth[7].r[2][3] = 0;
			meth[7].r[3][1] = 0;  meth[7].r[3][2] = 0;  meth[7].r[3][3] = 0;
			meth[7].r[4][1] = 0;  meth[7].r[4][2] = 0;  meth[7].r[4][3] = 0;
			meth[7].r[5][1] = 0;  meth[7].r[5][2] = 0;  meth[7].r[5][3] = 0;

			meth[8].r[1][1] = 3;  meth[8].r[1][2] = 6;  meth[8].r[1][3] = 0;
			meth[8].r[2][1] = 0;  meth[8].r[2][2] = 0;  meth[8].r[2][3] = 0;
			meth[8].r[3][1] = 0;  meth[8].r[3][2] = 0;  meth[8].r[3][3] = 0;
			meth[8].r[4][1] = 0;  meth[8].r[4][2] = 0;  meth[8].r[4][3] = 0;
			meth[8].r[5][1] = 0;  meth[8].r[5][2] = 0;  meth[8].r[5][3] = 0;

			meth[9].r[1][1] = 3;  meth[9].r[1][2] = 0;  meth[9].r[1][3] = 0;
			meth[9].r[2][1] = 0;  meth[9].r[2][2] = 0;  meth[9].r[2][3] = 0;
			meth[9].r[3][1] = 0;  meth[9].r[3][2] = 0;  meth[9].r[3][3] = 0;
			meth[9].r[4][1] = 0;  meth[9].r[4][2] = 0;  meth[9].r[4][3] = 0;
			meth[9].r[5][1] = 0;  meth[9].r[5][2] = 0;  meth[9].r[5][3] = 0;

			meth[10].r[1][1] = 5;  meth[10].r[1][2] = 6;  meth[10].r[1][3] = 0;
			meth[10].r[2][1] = 0;  meth[10].r[2][2] = 0;  meth[10].r[2][3] = 0;
			meth[10].r[3][1] = 0;  meth[10].r[3][2] = 0;  meth[10].r[3][3] = 0;
			meth[10].r[4][1] = 0;  meth[10].r[4][2] = 0;  meth[10].r[4][3] = 0;
			meth[10].r[5][1] = 0;  meth[10].r[5][2] = 0;  meth[10].r[5][3] = 0;

			meth[11].r[1][1] = 5;  meth[11].r[1][2] = 0;  meth[11].r[1][3] = 0;
			meth[11].r[2][1] = 0;  meth[11].r[2][2] = 0;  meth[11].r[2][3] = 0;
			meth[11].r[3][1] = 0;  meth[11].r[3][2] = 0;  meth[11].r[3][3] = 0;
			meth[11].r[4][1] = 0;  meth[11].r[4][2] = 0;  meth[11].r[4][3] = 0;
			meth[11].r[5][1] = 0;  meth[11].r[5][2] = 0;  meth[11].r[5][3] = 0;

			meth[12].r[1][1] = 6;  meth[12].r[1][2] = 7;  meth[12].r[1][3] = 0;
			meth[12].r[2][1] = 0;  meth[12].r[2][2] = 0;  meth[12].r[2][3] = 0;
			meth[12].r[3][1] = 0;  meth[12].r[3][2] = 0;  meth[12].r[3][3] = 0;
			meth[12].r[4][1] = 0;  meth[12].r[4][2] = 0;  meth[12].r[4][3] = 0;
			meth[12].r[5][1] = 0;  meth[12].r[5][2] = 0;  meth[12].r[5][3] = 0;

			meth[13].r[1][1] = 6;  meth[13].r[1][2] = 0;  meth[13].r[1][3] = 0;
			meth[13].r[2][1] = 0;  meth[13].r[2][2] = 0;  meth[13].r[2][3] = 0;
			meth[13].r[3][1] = 0;  meth[13].r[3][2] = 0;  meth[13].r[3][3] = 0;
			meth[13].r[4][1] = 0;  meth[13].r[4][2] = 0;  meth[13].r[4][3] = 0;
			meth[13].r[5][1] = 0;  meth[13].r[5][2] = 0;  meth[13].r[5][3] = 0;

			meth[14].r[1][1] = 7;  meth[14].r[1][2] = 0;  meth[14].r[1][3] = 0;
			meth[14].r[2][1] = 0;  meth[14].r[2][2] = 0;  meth[14].r[2][3] = 0;
			meth[14].r[3][1] = 0;  meth[14].r[3][2] = 0;  meth[14].r[3][3] = 0;
			meth[14].r[4][1] = 0;  meth[14].r[4][2] = 0;  meth[14].r[4][3] = 0;
			meth[14].r[5][1] = 0;  meth[14].r[5][2] = 0;  meth[14].r[5][3] = 0;

			meth[15].r[1][1] = 8;  meth[15].r[1][2] = 0;  meth[15].r[1][3] = 0;
			meth[15].r[2][1] = 0;  meth[15].r[2][2] = 0;  meth[15].r[2][3] = 0;
			meth[15].r[3][1] = 0;  meth[15].r[3][2] = 0;  meth[15].r[3][3] = 0;
			meth[15].r[4][1] = 0;  meth[15].r[4][2] = 0;  meth[15].r[4][3] = 0;
			meth[15].r[5][1] = 0;  meth[15].r[5][2] = 0;  meth[15].r[5][3] = 0;
			//-----------------------------------------------------------------
			meth[16].r[1][1] = 1;  meth[16].r[1][2] = 3;  meth[16].r[1][3] = 0;
			meth[16].r[2][1] = 0;  meth[16].r[2][2] = 0;  meth[16].r[2][3] = 0;
			meth[16].r[3][1] = 0;  meth[16].r[3][2] = 0;  meth[16].r[3][3] = 0;
			meth[16].r[4][1] = 0;  meth[16].r[4][2] = 0;  meth[16].r[4][3] = 0;
			meth[16].r[5][1] = 0;  meth[16].r[5][2] = 0;  meth[16].r[5][3] = 0;

			meth[17].r[1][1] = 1;  meth[17].r[1][2] = 5;  meth[17].r[1][3] = 0;
			meth[17].r[2][1] = 0;  meth[17].r[2][2] = 0;  meth[17].r[2][3] = 0;
			meth[17].r[3][1] = 0;  meth[17].r[3][2] = 0;  meth[17].r[3][3] = 0;
			meth[17].r[4][1] = 0;  meth[17].r[4][2] = 0;  meth[17].r[4][3] = 0;
			meth[17].r[5][1] = 0;  meth[17].r[5][2] = 0;  meth[17].r[5][3] = 0;

			meth[18].r[1][1] = 6;  meth[18].r[1][2] = 0;  meth[18].r[1][3] = 0;
			meth[18].r[2][1] = 0;  meth[18].r[2][2] = 0;  meth[18].r[2][3] = 0;
			meth[18].r[3][1] = 0;  meth[18].r[3][2] = 0;  meth[18].r[3][3] = 0;
			meth[18].r[4][1] = 0;  meth[18].r[4][2] = 0;  meth[18].r[4][3] = 0;
			meth[18].r[5][1] = 0;  meth[18].r[5][2] = 0;  meth[18].r[5][3] = 0;

			meth[19].r[1][1] = 1;  meth[19].r[1][2] = 6;  meth[19].r[1][3] = 0;
			meth[19].r[2][1] = 0;  meth[19].r[2][2] = 0;  meth[19].r[2][3] = 0;
			meth[19].r[3][1] = 0;  meth[19].r[3][2] = 0;  meth[19].r[3][3] = 0;
			meth[19].r[4][1] = 0;  meth[19].r[4][2] = 0;  meth[19].r[4][3] = 0;
			meth[19].r[5][1] = 0;  meth[19].r[5][2] = 0;  meth[19].r[5][3] = 0;

			meth[20].r[1][1] = 2;  meth[20].r[1][2] = 7;  meth[20].r[1][3] = 0;
			meth[20].r[2][1] = 0;  meth[20].r[2][2] = 0;  meth[20].r[2][3] = 0;
			meth[20].r[3][1] = 0;  meth[20].r[3][2] = 0;  meth[20].r[3][3] = 0;
			meth[20].r[4][1] = 0;  meth[20].r[4][2] = 0;  meth[20].r[4][3] = 0;
			meth[20].r[5][1] = 0;  meth[20].r[5][2] = 0;  meth[20].r[5][3] = 0;

			meth[21].r[1][1] = 2;  meth[21].r[1][2] = 3;  meth[21].r[1][3] = 0;
			meth[21].r[2][1] = 0;  meth[21].r[2][2] = 0;  meth[21].r[2][3] = 0;
			meth[21].r[3][1] = 0;  meth[21].r[3][2] = 0;  meth[21].r[3][3] = 0;
			meth[21].r[4][1] = 0;  meth[21].r[4][2] = 0;  meth[21].r[4][3] = 0;
			meth[21].r[5][1] = 0;  meth[21].r[5][2] = 0;  meth[21].r[5][3] = 0;

			meth[22].r[1][1] = 2;  meth[22].r[1][2] = 4;  meth[22].r[1][3] = 0;
			meth[22].r[2][1] = 0;  meth[22].r[2][2] = 0;  meth[22].r[2][3] = 0;
			meth[22].r[3][1] = 0;  meth[22].r[3][2] = 0;  meth[22].r[3][3] = 0;
			meth[22].r[4][1] = 0;  meth[22].r[4][2] = 0;  meth[22].r[4][3] = 0;
			meth[22].r[5][1] = 0;  meth[22].r[5][2] = 0;  meth[22].r[5][3] = 0;

			meth[23].r[1][1] = 3;  meth[23].r[1][2] = 6;  meth[23].r[1][3] = 0;
			meth[23].r[2][1] = 0;  meth[23].r[2][2] = 0;  meth[23].r[2][3] = 0;
			meth[23].r[3][1] = 0;  meth[23].r[3][2] = 0;  meth[23].r[3][3] = 0;
			meth[23].r[4][1] = 0;  meth[23].r[4][2] = 0;  meth[23].r[4][3] = 0;
			meth[23].r[5][1] = 0;  meth[23].r[5][2] = 0;  meth[23].r[5][3] = 0;

			meth[24].r[1][1] = 3;  meth[24].r[1][2] = 0;  meth[24].r[1][3] = 0;
			meth[24].r[2][1] = 0;  meth[24].r[2][2] = 0;  meth[24].r[2][3] = 0;
			meth[24].r[3][1] = 0;  meth[24].r[3][2] = 0;  meth[24].r[3][3] = 0;
			meth[24].r[4][1] = 0;  meth[24].r[4][2] = 0;  meth[24].r[4][3] = 0;
			meth[24].r[5][1] = 0;  meth[24].r[5][2] = 0;  meth[24].r[5][3] = 0;

			meth[25].r[1][1] = 5;  meth[25].r[1][2] = 6;  meth[25].r[1][3] = 0;
			meth[25].r[2][1] = 0;  meth[25].r[2][2] = 0;  meth[25].r[2][3] = 0;
			meth[25].r[3][1] = 0;  meth[25].r[3][2] = 0;  meth[25].r[3][3] = 0;
			meth[25].r[4][1] = 0;  meth[25].r[4][2] = 0;  meth[25].r[4][3] = 0;
			meth[25].r[5][1] = 0;  meth[25].r[5][2] = 0;  meth[25].r[5][3] = 0;

			meth[26].r[1][1] = 5;  meth[26].r[1][2] = 0;  meth[26].r[1][3] = 0;
			meth[26].r[2][1] = 0;  meth[26].r[2][2] = 0;  meth[26].r[2][3] = 0;
			meth[26].r[3][1] = 0;  meth[26].r[3][2] = 0;  meth[26].r[3][3] = 0;
			meth[26].r[4][1] = 0;  meth[26].r[4][2] = 0;  meth[26].r[4][3] = 0;
			meth[26].r[5][1] = 0;  meth[26].r[5][2] = 0;  meth[26].r[5][3] = 0;

			meth[27].r[1][1] = 6;  meth[27].r[1][2] = 7;  meth[27].r[1][3] = 0;
			meth[27].r[2][1] = 0;  meth[27].r[2][2] = 0;  meth[27].r[2][3] = 0;
			meth[27].r[3][1] = 0;  meth[27].r[3][2] = 0;  meth[27].r[3][3] = 0;
			meth[27].r[4][1] = 0;  meth[27].r[4][2] = 0;  meth[27].r[4][3] = 0;
			meth[27].r[5][1] = 0;  meth[27].r[5][2] = 0;  meth[27].r[5][3] = 0;

			meth[28].r[1][1] = 6;  meth[28].r[1][2] = 0;  meth[28].r[1][3] = 0;
			meth[28].r[2][1] = 0;  meth[28].r[2][2] = 0;  meth[28].r[2][3] = 0;
			meth[28].r[3][1] = 0;  meth[28].r[3][2] = 0;  meth[28].r[3][3] = 0;
			meth[28].r[4][1] = 0;  meth[28].r[4][2] = 0;  meth[28].r[4][3] = 0;
			meth[28].r[5][1] = 0;  meth[28].r[5][2] = 0;  meth[28].r[5][3] = 0;

			meth[29].r[1][1] = 7;  meth[29].r[1][2] = 0;  meth[29].r[1][3] = 0;
			meth[29].r[2][1] = 0;  meth[29].r[2][2] = 0;  meth[29].r[2][3] = 0;
			meth[29].r[3][1] = 0;  meth[29].r[3][2] = 0;  meth[29].r[3][3] = 0;
			meth[29].r[4][1] = 0;  meth[29].r[4][2] = 0;  meth[29].r[4][3] = 0;
			meth[29].r[5][1] = 0;  meth[29].r[5][2] = 0;  meth[29].r[5][3] = 0;

			meth[30].r[1][1] = 8;  meth[30].r[1][2] = 0;  meth[30].r[1][3] = 0;
			meth[30].r[2][1] = 0;  meth[30].r[2][2] = 0;  meth[30].r[2][3] = 0;
			meth[30].r[3][1] = 0;  meth[30].r[3][2] = 0;  meth[30].r[3][3] = 0;
			meth[30].r[4][1] = 0;  meth[30].r[4][2] = 0;  meth[30].r[4][3] = 0;
			meth[30].r[5][1] = 0;  meth[30].r[5][2] = 0;  meth[30].r[5][3] = 0;

			/***********************时间***********************/
			meth[1].time[1] = 2;  meth[1].time[2] = 0;  meth[1].time[3] = 0;  meth[1].time[4] = 0;  meth[1].time[5] = 0;

			meth[2].time[1] = 11;  meth[2].time[2] = 0;  meth[2].time[3] = 0;  meth[2].time[4] = 0;  meth[2].time[5] = 0;

			meth[3].time[1] = 1;  meth[3].time[2] = 0;  meth[3].time[3] = 0;  meth[3].time[4] = 0;  meth[3].time[5] = 0;

			meth[4].time[1] = 7;  meth[4].time[2] = 0;  meth[4].time[3] = 0;  meth[4].time[4] = 0;  meth[4].time[5] = 0;

			meth[5].time[1] = 14;  meth[5].time[2] = 0;  meth[5].time[3] = 0;  meth[5].time[4] = 0;  meth[5].time[5] = 0;

			meth[6].time[1] = 5;  meth[6].time[2] = 0;  meth[6].time[3] = 0;  meth[6].time[4] = 0;  meth[6].time[5] = 0;

			meth[7].time[1] = 6;  meth[7].time[2] = 0;  meth[7].time[3] = 0;  meth[7].time[4] = 0;  meth[7].time[5] = 0;

			meth[8].time[1] = 6;  meth[8].time[2] = 0;  meth[8].time[3] = 0;  meth[8].time[4] = 0;  meth[8].time[5] = 0;

			meth[9].time[1] = 13;  meth[9].time[2] = 0;  meth[9].time[3] = 0;  meth[9].time[4] = 0;  meth[9].time[5] = 0;

			meth[10].time[1] = 2;  meth[10].time[2] = 0;  meth[10].time[3] = 0;  meth[10].time[4] = 0;  meth[10].time[5] = 0;

			meth[11].time[1] = 14;  meth[11].time[2] = 0;  meth[11].time[3] = 0;  meth[11].time[4] = 0;  meth[11].time[5] = 0;

			meth[12].time[1] = 4;  meth[12].time[2] = 0;  meth[12].time[3] = 0;  meth[12].time[4] = 0;  meth[12].time[5] = 0;

			meth[13].time[1] = 14;  meth[13].time[2] = 0;  meth[13].time[3] = 0;  meth[13].time[4] = 0;  meth[13].time[5] = 0;

			meth[14].time[1] = 10;  meth[14].time[2] = 0;  meth[14].time[3] = 0;  meth[14].time[4] = 0;  meth[14].time[5] = 0;

			meth[15].time[1] = 4;  meth[15].time[2] = 0;  meth[15].time[3] = 0;  meth[15].time[4] = 0;  meth[15].time[5] = 0;
			//-------------------------------------------------------------------------------------------------------------

			meth[16].time[1] = 2;  meth[16].time[2] = 0;  meth[16].time[3] = 0;  meth[16].time[4] = 0;  meth[16].time[5] = 0;

			meth[17].time[1] = 11;  meth[17].time[2] = 0;  meth[17].time[3] = 0;  meth[17].time[4] = 0;  meth[17].time[5] = 0;

			meth[18].time[1] = 1;  meth[18].time[2] = 0;  meth[18].time[3] = 0;  meth[18].time[4] = 0;  meth[18].time[5] = 0;

			meth[19].time[1] = 7;  meth[19].time[2] = 0;  meth[19].time[3] = 0;  meth[19].time[4] = 0;  meth[19].time[5] = 0;

			meth[20].time[1] = 14;  meth[20].time[2] = 0;  meth[20].time[3] = 0;  meth[20].time[4] = 0;  meth[20].time[5] = 0;

			meth[21].time[1] = 5;  meth[21].time[2] = 0;  meth[21].time[3] = 0;  meth[21].time[4] = 0;  meth[21].time[5] = 0;

			meth[22].time[1] = 6;  meth[22].time[2] = 0;  meth[22].time[3] = 0;  meth[22].time[4] = 0;  meth[22].time[5] = 0;

			meth[23].time[1] = 6;  meth[23].time[2] = 0;  meth[23].time[3] = 0;  meth[23].time[4] = 0;  meth[23].time[5] = 0;

			meth[24].time[1] = 13;  meth[24].time[2] = 0;  meth[24].time[3] = 0;  meth[24].time[4] = 0;  meth[24].time[5] = 0;

			meth[25].time[1] = 2;  meth[25].time[2] = 0;  meth[25].time[3] = 0;  meth[25].time[4] = 0;  meth[25].time[5] = 0;

			meth[26].time[1] = 14;  meth[26].time[2] = 0;  meth[26].time[3] = 0;  meth[26].time[4] = 0;  meth[26].time[5] = 0;

			meth[27].time[1] = 4;  meth[27].time[2] = 0;  meth[27].time[3] = 0;  meth[27].time[4] = 0;  meth[27].time[5] = 0;

			meth[28].time[1] = 14;  meth[28].time[2] = 0;  meth[28].time[3] = 0;  meth[28].time[4] = 0;  meth[28].time[5] = 0;

			meth[29].time[1] = 10;  meth[29].time[2] = 0;  meth[29].time[3] = 0;  meth[29].time[4] = 0;  meth[29].time[5] = 0;

			meth[30].time[1] = 4;  meth[30].time[2] = 0;  meth[30].time[3] = 0;  meth[30].time[4] = 0;  meth[30].time[5] = 0;

		}
		else
			if (!strcmp(prob,"PTTS40"))
			{
				/***********************方案***********************/
				meth[1].m[1] = 1;  meth[1].m[2] = 2;  meth[1].m[3] = 3;  meth[1].m[4] = 0;  meth[1].m[5] = 0;

				meth[2].m[1] = 1;  meth[2].m[2] = 2;  meth[2].m[3] = 3;  meth[2].m[4] = 4;  meth[2].m[5] = 0;

				meth[3].m[1] = 1;  meth[3].m[2] = 2;  meth[3].m[3] = 0;  meth[3].m[4] = 0;  meth[3].m[5] = 0;

				meth[4].m[1] = 1;  meth[4].m[2] = 2;  meth[4].m[3] = 0;  meth[4].m[4] = 0;  meth[4].m[5] = 0;

				meth[5].m[1] = 1;  meth[5].m[2] = 0;  meth[5].m[3] = 0;  meth[5].m[4] = 0;  meth[5].m[5] = 0;

				meth[6].m[1] = 1;  meth[6].m[2] = 2;  meth[6].m[3] = 3;  meth[6].m[4] = 0;  meth[6].m[5] = 0;

				meth[7].m[1] = 1;  meth[7].m[2] = 2;  meth[7].m[3] = 3;  meth[7].m[4] = 0;  meth[7].m[5] = 0;

				meth[8].m[1] = 1;  meth[8].m[2] = 2;  meth[8].m[3] = 3;  meth[8].m[4] = 0;  meth[8].m[5] = 0;

				meth[9].m[1] = 1;  meth[9].m[2] = 2;  meth[9].m[3] = 3;  meth[9].m[4] = 0;  meth[9].m[5] = 0;

				meth[10].m[1] = 1;  meth[10].m[2] = 2;  meth[10].m[3] = 3;  meth[10].m[4] = 0;  meth[10].m[5] = 0;

				meth[11].m[1] = 1;  meth[11].m[2] = 2;  meth[11].m[3] = 3;  meth[11].m[4] = 0;  meth[11].m[5] = 0;

				meth[12].m[1] = 1;  meth[12].m[2] = 2;  meth[12].m[3] = 3;  meth[12].m[4] = 0;  meth[12].m[5] = 0;

				meth[13].m[1] = 1;  meth[13].m[2] = 2;  meth[13].m[3] = 3;  meth[13].m[4] = 0;  meth[13].m[5] = 0;

				meth[14].m[1] = 1;  meth[14].m[2] = 2;  meth[14].m[3] = 3;  meth[14].m[4] = 0;  meth[14].m[5] = 0;

				meth[15].m[1] = 1;  meth[15].m[2] = 0;  meth[15].m[3] = 0;  meth[15].m[4] = 0;  meth[15].m[5] = 0;

				meth[16].m[1] = 1;  meth[16].m[2] = 2;  meth[16].m[3] = 3;  meth[16].m[4] = 0;  meth[16].m[5] = 0;

				meth[17].m[1] = 1;  meth[17].m[2] = 2;  meth[17].m[3] = 3;  meth[17].m[4] = 0;  meth[17].m[5] = 0;

				meth[18].m[1] = 1;  meth[18].m[2] = 0;  meth[18].m[3] = 0;  meth[18].m[4] = 0;  meth[18].m[5] = 0;

				meth[19].m[1] = 1;  meth[19].m[2] = 2;  meth[19].m[3] = 3;  meth[19].m[4] = 4;  meth[19].m[5] = 0;

				meth[20].m[1] = 1;  meth[20].m[2] = 2;  meth[20].m[3] = 3;  meth[20].m[4] = 0;  meth[20].m[5] = 0;

				//////////////////////////////////////////////////////////////////////////////////////////////////
				meth[21].m[1] = 1;  meth[21].m[2] = 2;  meth[21].m[3] = 3;  meth[21].m[4] = 0;  meth[21].m[5] = 0;

				meth[22].m[1] = 1;  meth[22].m[2] = 2;  meth[22].m[3] = 3;  meth[22].m[4] = 4;  meth[22].m[5] = 0;

				meth[23].m[1] = 1;  meth[23].m[2] = 2;  meth[23].m[3] = 0;  meth[23].m[4] = 0;  meth[23].m[5] = 0;

				meth[24].m[1] = 1;  meth[24].m[2] = 2;  meth[24].m[3] = 0;  meth[24].m[4] = 0;  meth[24].m[5] = 0;

				meth[25].m[1] = 1;  meth[25].m[2] = 0;  meth[25].m[3] = 0;  meth[25].m[4] = 0;  meth[25].m[5] = 0;

				meth[26].m[1] = 1;  meth[26].m[2] = 2;  meth[26].m[3] = 3;  meth[26].m[4] = 0;  meth[26].m[5] = 0;

				meth[27].m[1] = 1;  meth[27].m[2] = 2;  meth[27].m[3] = 3;  meth[27].m[4] = 0;  meth[27].m[5] = 0;

				meth[28].m[1] = 1;  meth[28].m[2] = 2;  meth[28].m[3] = 3;  meth[28].m[4] = 0;  meth[28].m[5] = 0;

				meth[29].m[1] = 1;  meth[29].m[2] = 2;  meth[29].m[3] = 3;  meth[29].m[4] = 0;  meth[29].m[5] = 0;

				meth[30].m[1] = 1;  meth[30].m[2] = 2;  meth[30].m[3] = 3;  meth[30].m[4] = 0;  meth[30].m[5] = 0;

				meth[31].m[1] = 1;  meth[31].m[2] = 2;  meth[31].m[3] = 3;  meth[31].m[4] = 0;  meth[31].m[5] = 0;

				meth[32].m[1] = 1;  meth[32].m[2] = 2;  meth[32].m[3] = 3;  meth[32].m[4] = 0;  meth[32].m[5] = 0;

				meth[33].m[1] = 1;  meth[33].m[2] = 2;  meth[33].m[3] = 3;  meth[33].m[4] = 0;  meth[33].m[5] = 0;

				meth[34].m[1] = 1;  meth[34].m[2] = 2;  meth[34].m[3] = 3;  meth[34].m[4] = 0;  meth[34].m[5] = 0;

				meth[35].m[1] = 1;  meth[35].m[2] = 0;  meth[35].m[3] = 0;  meth[35].m[4] = 0;  meth[35].m[5] = 0;

				meth[36].m[1] = 1;  meth[36].m[2] = 2;  meth[36].m[3] = 3;  meth[36].m[4] = 0;  meth[36].m[5] = 0;

				meth[37].m[1] = 1;  meth[37].m[2] = 2;  meth[37].m[3] = 3;  meth[37].m[4] = 0;  meth[37].m[5] = 0;

				meth[38].m[1] = 1;  meth[38].m[2] = 0;  meth[38].m[3] = 0;  meth[38].m[4] = 0;  meth[38].m[5] = 0;

				meth[39].m[1] = 1;  meth[39].m[2] = 2;  meth[39].m[3] = 3;  meth[39].m[4] = 4;  meth[39].m[5] = 0;

				meth[40].m[1] = 1;  meth[40].m[2] = 2;  meth[40].m[3] = 3;  meth[40].m[4] = 0;  meth[40].m[5] = 0;

				/***********************资源***********************/
				meth[1].r[1][1] = 1;  meth[1].r[1][2] = 7;  meth[1].r[1][3] = 0;
				meth[1].r[2][1] = 3;  meth[1].r[2][2] = 5;  meth[1].r[2][3] = 0;
				meth[1].r[3][1] = 6;  meth[1].r[3][2] = 10;  meth[1].r[3][3] = 0;
				meth[1].r[4][1] = 0;  meth[1].r[4][2] = 0;  meth[1].r[4][3] = 0;
				meth[1].r[5][1] = 0;  meth[1].r[5][2] = 0;  meth[1].r[5][3] = 0;

				meth[2].r[1][1] = 2;  meth[2].r[1][2] = 11;  meth[2].r[1][3] = 0;
				meth[2].r[2][1] = 4;  meth[2].r[2][2] = 9;  meth[2].r[2][3] = 0;
				meth[2].r[3][1] = 5;  meth[2].r[3][2] = 6;  meth[2].r[3][3] = 0;
				meth[2].r[4][1] = 3;  meth[2].r[4][2] = 7;  meth[2].r[4][3] = 0;
				meth[2].r[5][1] = 0;  meth[2].r[5][2] = 0;  meth[2].r[5][3] = 0;

				meth[3].r[1][1] = 3;  meth[3].r[1][2] = 0;  meth[3].r[1][3] = 0;
				meth[3].r[2][1] = 12;  meth[3].r[2][2] = 0;  meth[3].r[2][3] = 0;
				meth[3].r[3][1] = 0;  meth[3].r[3][2] = 0;  meth[3].r[3][3] = 0;
				meth[3].r[4][1] = 0;  meth[3].r[4][2] = 0;  meth[3].r[4][3] = 0;
				meth[3].r[5][1] = 0;  meth[3].r[5][2] = 0;  meth[3].r[5][3] = 0;

				meth[4].r[1][1] = 9;  meth[4].r[1][2] = 0;  meth[4].r[1][3] = 0;
				meth[4].r[2][1] = 10;  meth[4].r[2][2] = 0;  meth[4].r[2][3] = 0;
				meth[4].r[3][1] = 0;  meth[4].r[3][2] = 0;  meth[4].r[3][3] = 0;
				meth[4].r[4][1] = 0;  meth[4].r[4][2] = 0;  meth[4].r[4][3] = 0;
				meth[4].r[5][1] = 0;  meth[4].r[5][2] = 0;  meth[4].r[5][3] = 0;

				meth[5].r[1][1] = 12;  meth[5].r[1][2] = 0;  meth[5].r[1][3] = 0;
				meth[5].r[2][1] = 0;  meth[5].r[2][2] = 0;  meth[5].r[2][3] = 0;
				meth[5].r[3][1] = 0;  meth[5].r[3][2] = 0;  meth[5].r[3][3] = 0;
				meth[5].r[4][1] = 0;  meth[5].r[4][2] = 0;  meth[5].r[4][3] = 0;
				meth[5].r[5][1] = 0;  meth[5].r[5][2] = 0;  meth[5].r[5][3] = 0;

				meth[6].r[1][1] = 1;  meth[6].r[1][2] = 4;  meth[6].r[1][3] = 0;
				meth[6].r[2][1] = 3;  meth[6].r[2][2] = 7;  meth[6].r[2][3] = 0;
				meth[6].r[3][1] = 6;  meth[6].r[3][2] = 8;  meth[6].r[3][3] = 0;
				meth[6].r[4][1] = 0;  meth[6].r[4][2] = 0;  meth[6].r[4][3] = 0;
				meth[6].r[5][1] = 0;  meth[6].r[5][2] = 0;  meth[6].r[5][3] = 0;

				meth[7].r[1][1] = 1;  meth[7].r[1][2] = 2;  meth[7].r[1][3] = 0;
				meth[7].r[2][1] = 3;  meth[7].r[2][2] = 8;  meth[7].r[2][3] = 0;
				meth[7].r[3][1] = 7;  meth[7].r[3][2] = 11;  meth[7].r[3][3] = 0;
				meth[7].r[4][1] = 0;  meth[7].r[4][2] = 0;  meth[7].r[4][3] = 0;
				meth[7].r[5][1] = 0;  meth[7].r[5][2] = 0;  meth[7].r[5][3] = 0;

				meth[8].r[1][1] = 1;  meth[8].r[1][2] = 3;  meth[8].r[1][3] = 0;
				meth[8].r[2][1] = 6;  meth[8].r[2][2] = 10;  meth[8].r[2][3] = 0;
				meth[8].r[3][1] = 7;  meth[8].r[3][2] = 12;  meth[8].r[3][3] = 0;
				meth[8].r[4][1] = 0;  meth[8].r[4][2] = 0;  meth[8].r[4][3] = 0;
				meth[8].r[5][1] = 0;  meth[8].r[5][2] = 0;  meth[8].r[5][3] = 0;

				meth[9].r[1][1] = 1;  meth[9].r[1][2] = 4;  meth[9].r[1][3] = 0;
				meth[9].r[2][1] = 7;  meth[9].r[2][2] = 9;  meth[9].r[2][3] = 0;
				meth[9].r[3][1] = 8;  meth[9].r[3][2] = 11;  meth[9].r[3][3] = 0;
				meth[9].r[4][1] = 0;  meth[9].r[4][2] = 0;  meth[9].r[4][3] = 0;
				meth[9].r[5][1] = 0;  meth[9].r[5][2] = 0;  meth[9].r[5][3] = 0;

				meth[10].r[1][1] = 2;  meth[10].r[1][2] = 0;  meth[10].r[1][3] = 0;
				meth[10].r[2][1] = 4;  meth[10].r[2][2] = 0;  meth[10].r[2][3] = 0;
				meth[10].r[3][1] = 10;  meth[10].r[3][2] = 0;  meth[10].r[3][3] = 0;
				meth[10].r[4][1] = 0;  meth[10].r[4][2] = 0;  meth[10].r[4][3] = 0;
				meth[10].r[5][1] = 0;  meth[10].r[5][2] = 0;  meth[10].r[5][3] = 0;

				meth[11].r[1][1] = 2;  meth[11].r[1][2] = 7;  meth[11].r[1][3] = 0;
				meth[11].r[2][1] = 3;  meth[11].r[2][2] = 12;  meth[11].r[2][3] = 0;
				meth[11].r[3][1] = 8;  meth[11].r[3][2] = 9;  meth[11].r[3][3] = 0;
				meth[11].r[4][1] = 0;  meth[11].r[4][2] = 0;  meth[11].r[4][3] = 0;
				meth[11].r[5][1] = 0;  meth[11].r[5][2] = 0;  meth[11].r[5][3] = 0;

				meth[12].r[1][1] = 2;  meth[12].r[1][2] = 0;  meth[12].r[1][3] = 0;
				meth[12].r[2][1] = 5;  meth[12].r[2][2] = 0;  meth[12].r[2][3] = 0;
				meth[12].r[3][1] = 11;  meth[12].r[3][2] = 0;  meth[12].r[3][3] = 0;
				meth[12].r[4][1] = 0;  meth[12].r[4][2] = 0;  meth[12].r[4][3] = 0;
				meth[12].r[5][1] = 0;  meth[12].r[5][2] = 0;  meth[12].r[5][3] = 0;

				meth[13].r[1][1] = 2;  meth[13].r[1][2] = 0;  meth[13].r[1][3] = 0;
				meth[13].r[2][1] = 8;  meth[13].r[2][2] = 0;  meth[13].r[2][3] = 0;
				meth[13].r[3][1] = 9;  meth[13].r[3][2] = 0;  meth[13].r[3][3] = 0;
				meth[13].r[4][1] = 0;  meth[13].r[4][2] = 0;  meth[13].r[4][3] = 0;
				meth[13].r[5][1] = 0;  meth[13].r[5][2] = 0;  meth[13].r[5][3] = 0;

				meth[14].r[1][1] = 3;  meth[14].r[1][2] = 0;  meth[14].r[1][3] = 0;
				meth[14].r[2][1] = 11;  meth[14].r[2][2] = 0;  meth[14].r[2][3] = 0;
				meth[14].r[3][1] = 12;  meth[14].r[3][2] = 0;  meth[14].r[3][3] = 0;
				meth[14].r[4][1] = 0;  meth[14].r[4][2] = 0;  meth[14].r[4][3] = 0;
				meth[14].r[5][1] = 0;  meth[14].r[5][2] = 0;  meth[14].r[5][3] = 0;

				meth[15].r[1][1] = 12;  meth[15].r[1][2] = 0;  meth[15].r[1][3] = 0;
				meth[15].r[2][1] = 0;  meth[15].r[2][2] = 0;  meth[15].r[2][3] = 0;
				meth[15].r[3][1] = 0;  meth[15].r[3][2] = 0;  meth[15].r[3][3] = 0;
				meth[15].r[4][1] = 0;  meth[15].r[4][2] = 0;  meth[15].r[4][3] = 0;
				meth[15].r[5][1] = 0;  meth[15].r[5][2] = 0;  meth[15].r[5][3] = 0;

				meth[16].r[1][1] = 2;  meth[16].r[1][2] = 0;  meth[16].r[1][3] = 0;
				meth[16].r[2][1] = 5;  meth[16].r[2][2] = 0;  meth[16].r[2][3] = 0;
				meth[16].r[3][1] = 8;  meth[16].r[3][2] = 0;  meth[16].r[3][3] = 0;
				meth[16].r[4][1] = 0;  meth[16].r[4][2] = 0;  meth[16].r[4][3] = 0;
				meth[16].r[5][1] = 0;  meth[16].r[5][2] = 0;  meth[16].r[5][3] = 0;

				meth[17].r[1][1] = 1;  meth[17].r[1][2] = 10;  meth[17].r[1][3] = 0;
				meth[17].r[2][1] = 5;  meth[17].r[2][2] = 9;  meth[17].r[2][3] = 0;
				meth[17].r[3][1] = 11;  meth[17].r[3][2] = 12;  meth[17].r[3][3] = 0;
				meth[17].r[4][1] = 0;  meth[17].r[4][2] = 0;  meth[17].r[4][3] = 0;
				meth[17].r[5][1] = 0;  meth[17].r[5][2] = 0;  meth[17].r[5][3] = 0;

				meth[18].r[1][1] = 6;  meth[18].r[1][2] = 0;  meth[18].r[1][3] = 0;
				meth[18].r[2][1] = 0;  meth[18].r[2][2] = 0;  meth[18].r[2][3] = 0;
				meth[18].r[3][1] = 0;  meth[18].r[3][2] = 0;  meth[18].r[3][3] = 0;
				meth[18].r[4][1] = 0;  meth[18].r[4][2] = 0;  meth[18].r[4][3] = 0;
				meth[18].r[5][1] = 0;  meth[18].r[5][2] = 0;  meth[18].r[5][3] = 0;

				meth[19].r[1][1] = 2;  meth[19].r[1][2] = 0;  meth[19].r[1][3] = 0;
				meth[19].r[2][1] = 5;  meth[19].r[2][2] = 0;  meth[19].r[2][3] = 0;
				meth[19].r[3][1] = 10;  meth[19].r[3][2] = 0;  meth[19].r[3][3] = 0;
				meth[19].r[4][1] = 12;  meth[19].r[4][2] = 0;  meth[19].r[4][3] = 0;
				meth[19].r[5][1] = 0;  meth[19].r[5][2] = 0;  meth[19].r[5][3] = 0;

				meth[20].r[1][1] = 3;  meth[20].r[1][2] = 0;  meth[20].r[1][3] = 0;
				meth[20].r[2][1] = 6;  meth[20].r[2][2] = 0;  meth[20].r[2][3] = 0;
				meth[20].r[3][1] = 9;  meth[20].r[3][2] = 0;  meth[20].r[3][3] = 0;
				meth[20].r[4][1] = 0;  meth[20].r[4][2] = 0;  meth[20].r[4][3] = 0;
				meth[20].r[5][1] = 0;  meth[20].r[5][2] = 0;  meth[20].r[5][3] = 0;

				/////////////////////////////////////////////////////////////////////////
				meth[21].r[1][1] = 1;  meth[21].r[1][2] = 4;  meth[21].r[1][3] = 0;
				meth[21].r[2][1] = 3;  meth[21].r[2][2] = 5;  meth[21].r[2][3] = 0;
				meth[21].r[3][1] = 6;  meth[21].r[3][2] = 8;  meth[21].r[3][3] = 0;
				meth[21].r[4][1] = 0;  meth[21].r[4][2] = 0;  meth[21].r[4][3] = 0;
				meth[21].r[5][1] = 0;  meth[21].r[5][2] = 0;  meth[21].r[5][3] = 0;

				meth[22].r[1][1] = 2;  meth[22].r[1][2] = 0;  meth[22].r[1][3] = 0;
				meth[22].r[2][1] = 4;  meth[22].r[2][2] = 0;  meth[22].r[2][3] = 0;
				meth[22].r[3][1] = 6;  meth[22].r[3][2] = 0;  meth[22].r[3][3] = 0;
				meth[22].r[4][1] = 10;  meth[22].r[4][2] = 0;  meth[22].r[4][3] = 0;
				meth[22].r[5][1] = 0;  meth[22].r[5][2] = 0;  meth[22].r[5][3] = 0;

				meth[23].r[1][1] = 3;  meth[23].r[1][2] = 0;  meth[23].r[1][3] = 0;
				meth[23].r[2][1] = 12;  meth[23].r[2][2] = 0;  meth[23].r[2][3] = 0;
				meth[23].r[3][1] = 0;  meth[23].r[3][2] = 0;  meth[23].r[3][3] = 0;
				meth[23].r[4][1] = 0;  meth[23].r[4][2] = 0;  meth[23].r[4][3] = 0;
				meth[23].r[5][1] = 0;  meth[23].r[5][2] = 0;  meth[23].r[5][3] = 0;

				meth[24].r[1][1] = 4;  meth[24].r[1][2] = 0;  meth[24].r[1][3] = 0;
				meth[24].r[2][1] = 11;  meth[24].r[2][2] = 0;  meth[24].r[2][3] = 0;
				meth[24].r[3][1] = 0;  meth[24].r[3][2] = 0;  meth[24].r[3][3] = 0;
				meth[24].r[4][1] = 0;  meth[24].r[4][2] = 0;  meth[24].r[4][3] = 0;
				meth[24].r[5][1] = 0;  meth[24].r[5][2] = 0;  meth[24].r[5][3] = 0;

				meth[25].r[1][1] = 7;  meth[25].r[1][2] = 0;  meth[25].r[1][3] = 0;
				meth[25].r[2][1] = 0;  meth[25].r[2][2] = 0;  meth[25].r[2][3] = 0;
				meth[25].r[3][1] = 0;  meth[25].r[3][2] = 0;  meth[25].r[3][3] = 0;
				meth[25].r[4][1] = 0;  meth[25].r[4][2] = 0;  meth[25].r[4][3] = 0;
				meth[25].r[5][1] = 0;  meth[25].r[5][2] = 0;  meth[25].r[5][3] = 0;

				meth[26].r[1][1] = 1;  meth[26].r[1][2] = 4;  meth[26].r[1][3] = 0;
				meth[26].r[2][1] = 3;  meth[26].r[2][2] = 7;  meth[26].r[2][3] = 0;
				meth[26].r[3][1] = 6;  meth[26].r[3][2] = 8;  meth[26].r[3][3] = 0;
				meth[26].r[4][1] = 0;  meth[26].r[4][2] = 0;  meth[26].r[4][3] = 0;
				meth[26].r[5][1] = 0;  meth[26].r[5][2] = 0;  meth[26].r[5][3] = 0;

				meth[27].r[1][1] = 1;  meth[27].r[1][2] = 2;  meth[27].r[1][3] = 0;
				meth[27].r[2][1] = 1;  meth[27].r[2][2] = 7;  meth[27].r[2][3] = 0;
				meth[27].r[3][1] = 3;  meth[27].r[3][2] = 8;  meth[27].r[3][3] = 0;
				meth[27].r[4][1] = 0;  meth[27].r[4][2] = 0;  meth[27].r[4][3] = 0;
				meth[27].r[5][1] = 0;  meth[27].r[5][2] = 0;  meth[27].r[5][3] = 0;

				meth[28].r[1][1] = 1;  meth[28].r[1][2] = 3;  meth[28].r[1][3] = 0;
				meth[28].r[2][1] = 4;  meth[28].r[2][2] = 5;  meth[28].r[2][3] = 0;
				meth[28].r[3][1] = 7;  meth[28].r[3][2] = 12;  meth[28].r[3][3] = 0;
				meth[28].r[4][1] = 0;  meth[28].r[4][2] = 0;  meth[28].r[4][3] = 0;
				meth[28].r[5][1] = 0;  meth[28].r[5][2] = 0;  meth[28].r[5][3] = 0;

				meth[29].r[1][1] = 1;  meth[29].r[1][2] = 4;  meth[29].r[1][3] = 0;
				meth[29].r[2][1] = 3;  meth[29].r[2][2] = 4;  meth[29].r[2][3] = 0;
				meth[29].r[3][1] = 7;  meth[29].r[3][2] = 8;  meth[29].r[3][3] = 0;
				meth[29].r[4][1] = 0;  meth[29].r[4][2] = 0;  meth[29].r[4][3] = 0;
				meth[29].r[5][1] = 0;  meth[29].r[5][2] = 0;  meth[29].r[5][3] = 0;

				meth[30].r[1][1] = 1;  meth[30].r[1][2] = 0;  meth[30].r[1][3] = 0;
				meth[30].r[2][1] = 4;  meth[30].r[2][2] = 0;  meth[30].r[2][3] = 0;
				meth[30].r[3][1] = 12;  meth[30].r[3][2] = 0;  meth[30].r[3][3] = 0;
				meth[30].r[4][1] = 0;  meth[30].r[4][2] = 0;  meth[30].r[4][3] = 0;
				meth[30].r[5][1] = 0;  meth[30].r[5][2] = 0;  meth[30].r[5][3] = 0;

				meth[31].r[1][1] = 2;  meth[31].r[1][2] = 3;  meth[31].r[1][3] = 0;
				meth[31].r[2][1] = 5;  meth[31].r[2][2] = 11;  meth[31].r[2][3] = 0;
				meth[31].r[3][1] = 6;  meth[31].r[3][2] = 9;  meth[31].r[3][3] = 0;
				meth[31].r[4][1] = 0;  meth[31].r[4][2] = 0;  meth[31].r[4][3] = 0;
				meth[31].r[5][1] = 0;  meth[31].r[5][2] = 0;  meth[31].r[5][3] = 0;

				meth[32].r[1][1] = 2;  meth[32].r[1][2] = 0;  meth[32].r[1][3] = 0;
				meth[32].r[2][1] = 5;  meth[32].r[2][2] = 0;  meth[32].r[2][3] = 0;
				meth[32].r[3][1] = 6;  meth[32].r[3][2] = 0;  meth[32].r[3][3] = 0;
				meth[32].r[4][1] = 0;  meth[32].r[4][2] = 0;  meth[32].r[4][3] = 0;
				meth[32].r[5][1] = 0;  meth[32].r[5][2] = 0;  meth[32].r[5][3] = 0;

				meth[33].r[1][1] = 2;  meth[33].r[1][2] = 0;  meth[33].r[1][3] = 0;
				meth[33].r[2][1] = 6;  meth[33].r[2][2] = 0;  meth[33].r[2][3] = 0;
				meth[33].r[3][1] = 11;  meth[33].r[3][2] = 0;  meth[33].r[3][3] = 0;
				meth[33].r[4][1] = 0;  meth[33].r[4][2] = 0;  meth[33].r[4][3] = 0;
				meth[33].r[5][1] = 0;  meth[33].r[5][2] = 0;  meth[33].r[5][3] = 0;

				meth[34].r[1][1] = 3;  meth[34].r[1][2] = 0;  meth[34].r[1][3] = 0;
				meth[34].r[2][1] = 7;  meth[34].r[2][2] = 0;  meth[34].r[2][3] = 0;
				meth[34].r[3][1] = 12;  meth[34].r[3][2] = 0;  meth[34].r[3][3] = 0;
				meth[34].r[4][1] = 0;  meth[34].r[4][2] = 0;  meth[34].r[4][3] = 0;
				meth[34].r[5][1] = 0;  meth[34].r[5][2] = 0;  meth[34].r[5][3] = 0;

				meth[35].r[1][1] = 9;  meth[35].r[1][2] = 0;  meth[35].r[1][3] = 0;
				meth[35].r[2][1] = 0;  meth[35].r[2][2] = 0;  meth[35].r[2][3] = 0;
				meth[35].r[3][1] = 0;  meth[35].r[3][2] = 0;  meth[35].r[3][3] = 0;
				meth[35].r[4][1] = 0;  meth[35].r[4][2] = 0;  meth[35].r[4][3] = 0;
				meth[35].r[5][1] = 0;  meth[35].r[5][2] = 0;  meth[35].r[5][3] = 0;

				meth[36].r[1][1] = 2;  meth[36].r[1][2] = 0;  meth[36].r[1][3] = 0;
				meth[36].r[2][1] = 5;  meth[36].r[2][2] = 0;  meth[36].r[2][3] = 0;
				meth[36].r[3][1] = 10;  meth[36].r[3][2] = 0;  meth[36].r[3][3] = 0;
				meth[36].r[4][1] = 0;  meth[36].r[4][2] = 0;  meth[36].r[4][3] = 0;
				meth[36].r[5][1] = 0;  meth[36].r[5][2] = 0;  meth[36].r[5][3] = 0;

				meth[37].r[1][1] = 1;  meth[37].r[1][2] = 2;  meth[37].r[1][3] = 0;
				meth[37].r[2][1] = 7;  meth[37].r[2][2] = 11;  meth[37].r[2][3] = 0;
				meth[37].r[3][1] = 5;  meth[37].r[3][2] = 12;  meth[37].r[3][3] = 0;
				meth[37].r[4][1] = 0;  meth[37].r[4][2] = 0;  meth[37].r[4][3] = 0;
				meth[37].r[5][1] = 0;  meth[37].r[5][2] = 0;  meth[37].r[5][3] = 0;

				meth[38].r[1][1] = 10;  meth[38].r[1][2] = 0;  meth[38].r[1][3] = 0;
				meth[38].r[2][1] = 0;  meth[38].r[2][2] = 0;  meth[38].r[2][3] = 0;
				meth[38].r[3][1] = 0;  meth[38].r[3][2] = 0;  meth[38].r[3][3] = 0;
				meth[38].r[4][1] = 0;  meth[38].r[4][2] = 0;  meth[38].r[4][3] = 0;
				meth[38].r[5][1] = 0;  meth[38].r[5][2] = 0;  meth[38].r[5][3] = 0;

				meth[39].r[1][1] = 4;  meth[39].r[1][2] = 0;  meth[39].r[1][3] = 0;
				meth[39].r[2][1] = 6;  meth[39].r[2][2] = 0;  meth[39].r[2][3] = 0;
				meth[39].r[3][1] = 9;  meth[39].r[3][2] = 0;  meth[39].r[3][3] = 0;
				meth[39].r[4][1] = 10;  meth[39].r[4][2] = 0;  meth[39].r[4][3] = 0;
				meth[39].r[5][1] = 0;  meth[39].r[5][2] = 0;  meth[39].r[5][3] = 0;

				meth[40].r[1][1] = 3;  meth[40].r[1][2] = 0;  meth[40].r[1][3] = 0;
				meth[40].r[2][1] = 6;  meth[40].r[2][2] = 0;  meth[40].r[2][3] = 0;
				meth[40].r[3][1] = 9;  meth[40].r[3][2] = 0;  meth[40].r[3][3] = 0;
				meth[40].r[4][1] = 0;  meth[40].r[4][2] = 0;  meth[40].r[4][3] = 0;
				meth[40].r[5][1] = 0;  meth[40].r[5][2] = 0;  meth[40].r[5][3] = 0;

				/***********************时间***********************/
				meth[1].time[1] = 5;  meth[1].time[2] = 5;  meth[1].time[3] = 4;  meth[1].time[4] = 0;  meth[1].time[5] = 0;

				meth[2].time[1] = 5;  meth[2].time[2] = 4;  meth[2].time[3] = 6;  meth[2].time[4] = 4;  meth[2].time[5] = 0;

				meth[3].time[1] = 7;  meth[3].time[2] = 5;  meth[3].time[3] = 0;  meth[3].time[4] = 0;  meth[3].time[5] = 0;

				meth[4].time[1] = 25;  meth[4].time[2] = 22;  meth[4].time[3] = 0;  meth[4].time[4] = 0;  meth[4].time[5] = 0;

				meth[5].time[1] = 14;  meth[5].time[2] = 0;  meth[5].time[3] = 0;  meth[5].time[4] = 0;  meth[5].time[5] = 0;

				meth[6].time[1] = 7;  meth[6].time[2] = 8;  meth[6].time[3] = 8;  meth[6].time[4] = 0;  meth[6].time[5] = 0;

				meth[7].time[1] = 4;  meth[7].time[2] = 2;  meth[7].time[3] = 3;  meth[7].time[4] = 0;  meth[7].time[5] = 0;

				meth[8].time[1] = 5;  meth[8].time[2] = 4;  meth[8].time[3] = 7;  meth[8].time[4] = 0;  meth[8].time[5] = 0;

				meth[9].time[1] = 11;  meth[9].time[2] = 13;  meth[9].time[3] = 12;  meth[9].time[4] = 0;  meth[9].time[5] = 0;

				meth[10].time[1] = 9;  meth[10].time[2] = 10;  meth[10].time[3] = 10;  meth[10].time[4] = 0;  meth[10].time[5] = 0;

				meth[11].time[1] = 6;  meth[11].time[2] = 9;  meth[11].time[3] = 8;  meth[11].time[4] = 0;  meth[11].time[5] = 0;

				meth[12].time[1] = 11;  meth[12].time[2] = 13;  meth[12].time[3] = 15;  meth[12].time[4] = 0;  meth[12].time[5] = 0;

				meth[13].time[1] = 4;  meth[13].time[2] = 5;  meth[13].time[3] = 7;  meth[13].time[4] = 0;  meth[13].time[5] = 0;

				meth[14].time[1] = 7;  meth[14].time[2] = 10;  meth[14].time[3] = 8;  meth[14].time[4] = 0;  meth[14].time[5] = 0;

				meth[15].time[1] = 2;  meth[15].time[2] = 0;  meth[15].time[3] = 0;  meth[15].time[4] = 0;  meth[15].time[5] = 0;

				meth[16].time[1] = 9;  meth[16].time[2] = 7;  meth[16].time[3] = 6;  meth[16].time[4] = 0;  meth[16].time[5] = 0;

				meth[17].time[1] = 10;  meth[17].time[2] = 12;  meth[17].time[3] = 11;  meth[17].time[4] = 0;  meth[17].time[5] = 0;

				meth[18].time[1] = 15;  meth[18].time[2] = 0;  meth[18].time[3] = 0;  meth[18].time[4] = 0;  meth[18].time[5] = 0;

				meth[19].time[1] = 8;  meth[19].time[2] = 7;  meth[19].time[3] = 7;  meth[19].time[4] = 6;  meth[19].time[5] = 0;

				meth[20].time[1] = 6;  meth[20].time[2] = 4;  meth[20].time[3] = 5;  meth[20].time[4] = 0;  meth[20].time[5] = 0;

				////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				meth[21].time[1] = 2;  meth[21].time[2] = 5;  meth[21].time[3] = 3;  meth[21].time[4] = 0;  meth[21].time[5] = 0;

				meth[22].time[1] = 3;  meth[22].time[2] = 4;  meth[22].time[3] = 3;  meth[22].time[4] = 4;  meth[22].time[5] = 0;

				meth[23].time[1] = 5;  meth[23].time[2] = 5;  meth[23].time[3] = 0;  meth[23].time[4] = 0;  meth[23].time[5] = 0;

				meth[24].time[1] = 14;  meth[24].time[2] = 17;  meth[24].time[3] = 0;  meth[24].time[4] = 0;  meth[24].time[5] = 0;

				meth[25].time[1] = 19;  meth[25].time[2] = 0;  meth[25].time[3] = 0;  meth[25].time[4] = 0;  meth[25].time[5] = 0;

				meth[26].time[1] = 7;  meth[26].time[2] = 8;  meth[26].time[3] = 10;  meth[26].time[4] = 0;  meth[26].time[5] = 0;

				meth[27].time[1] = 2;  meth[27].time[2] = 2;  meth[27].time[3] = 4;  meth[27].time[4] = 0;  meth[27].time[5] = 0;

				meth[28].time[1] = 5;  meth[28].time[2] = 4;  meth[28].time[3] = 2;  meth[28].time[4] = 0;  meth[28].time[5] = 0;

				meth[29].time[1] = 11;  meth[29].time[2] = 15;  meth[29].time[3] = 12;  meth[29].time[4] = 0;  meth[29].time[5] = 0;

				meth[30].time[1] = 9;  meth[30].time[2] = 12;  meth[30].time[3] = 10;  meth[30].time[4] = 0;  meth[30].time[5] = 0;

				meth[31].time[1] = 6;  meth[31].time[2] = 8;  meth[31].time[3] = 8;  meth[31].time[4] = 0;  meth[31].time[5] = 0;

				meth[32].time[1] = 11;  meth[32].time[2] = 13;  meth[32].time[3] = 17;  meth[32].time[4] = 0;  meth[32].time[5] = 0;

				meth[33].time[1] = 6;  meth[33].time[2] = 5;  meth[33].time[3] = 4;  meth[33].time[4] = 0;  meth[33].time[5] = 0;

				meth[34].time[1] = 7;  meth[34].time[2] = 8;  meth[34].time[3] = 10;  meth[34].time[4] = 0;  meth[34].time[5] = 0;

				meth[35].time[1] = 2;  meth[35].time[2] = 0;  meth[35].time[3] = 0;  meth[35].time[4] = 0;  meth[35].time[5] = 0;

				meth[36].time[1] = 9;  meth[36].time[2] = 7;  meth[36].time[3] = 6;  meth[36].time[4] = 0;  meth[36].time[5] = 0;

				meth[37].time[1] = 10;  meth[37].time[2] = 7;  meth[37].time[3] = 11;  meth[37].time[4] = 0;  meth[37].time[5] = 0;

				meth[38].time[1] = 15;  meth[38].time[2] = 0;  meth[38].time[3] = 0;  meth[38].time[4] = 0;  meth[38].time[5] = 0;

				meth[39].time[1] = 8;  meth[39].time[2] = 7;  meth[39].time[3] = 7;  meth[39].time[4] = 6;  meth[39].time[5] = 0;

				meth[40].time[1] = 6;  meth[40].time[2] = 5;  meth[40].time[3] = 5;  meth[40].time[4] = 0;  meth[40].time[5] = 0;
			}

			/*************约束关系******************/
			if (!strcmp(prob,"PTTS"))
			{
				//6.8约束自造小例子1
				//restraint[0][2] = 1;// t1 > t3
				//restraint[2][0] = -1;
				//restraint[0][3] = 1;// t1 > t4
				//restraint[3][0] = -1;

				//restraint[1][4] = 1;// t2 > t5
				//restraint[4][1] = -1;

				//restraint[2][3] = 1;// t3 > t4
				//restraint[3][2] = -1;
				//restraint[2][4] = 1;// t3 > t5
				//restraint[4][2] = -1;

				//restraint[3][1] = 1;// t4 > t2
				//restraint[1][3] = -1;

				//restraint[4][5] = 1;// t5 > t6
				//restraint[5][4] = -1;

				//6.8约束自造小例子2
				//restraint[0][2] = 1;// t1 > t3
				//restraint[2][0] = -1;

				//restraint[2][3] = 1;// t3 > t4
				//restraint[3][2] = -1;

				//restraint[3][1] = 1;// t4 > t2
				//restraint[1][3] = -1;

				//20.8约束陈晓例子
				restraint[2-1][1-1] = 1;// t2 > t1
				restraint[1-1][2-1] = -1;

				restraint[15-1][1-1] = 1;// t15 > t1
				restraint[1-1][15-1] = -1;

				restraint[6-1][3-1] = 1;// t6 > t3
				restraint[3-1][6-1] = -1;

				restraint[11-1][3-1] = 1;// t11 > t3
				restraint[3-1][11-1] = -1;

				restraint[18-1][3-1] = 1;// t18 > t3
				restraint[3-1][18-1] = -1;

				restraint[3-1][4-1] = 1;// t3 > t4
				restraint[4-1][3-1] = -1;

				restraint[14-1][5-1] = 1;// t14 > t5
				restraint[5-1][14-1] = -1;

				restraint[1-1][6-1] = 1;// t1 > t6
				restraint[6-1][1-1] = -1;

				restraint[9-1][6-1] = 1;// t9 > t6
				restraint[6-1][9-1] = -1;

				restraint[19-1][6-1] = 1;// t19 > t6
				restraint[6-1][19-1] = -1;

				restraint[6-1][7-1] = 1;// t6 > t7
				restraint[7-1][6-1] = -1;

				restraint[2-1][9-1] = 1;// t2 > t9
				restraint[9-1][2-1] = -1;

				restraint[14-1][9-1] = 1;// t14 > t9
				restraint[9-1][14-1] = -1;

				restraint[7-1][12-1] = 1;// t7 > t12
				restraint[12-1][7-1] = -1;

				restraint[10-1][12-1] = 1;// t10 > t12
				restraint[12-1][10-1] = -1;

				restraint[19-1][12-1] = 1;// t19 > t12
				restraint[12-1][19-1] = -1;

				restraint[4-1][13-1] = 1;// t4 > t13
				restraint[13-1][4-1] = -1;

				restraint[17-1][13-1] = 1;// t17 > t13
				restraint[13-1][17-1] = -1;

				restraint[14-1][15-1] = 1;// t14 > t15
				restraint[15-1][14-1] = -1;

				restraint[19-1][15-1] = 1;// t19 > t15
				restraint[15-1][19-1] = -1;

				restraint[1-1][17-1] = 1;// t1 > t17
				restraint[17-1][1-1] = -1;

				restraint[9-1][17-1] = 1;// t9 > t17
				restraint[17-1][9-1] = -1;

				restraint[5-1][18-1] = 1;// t5 > t18
				restraint[18-1][5-1] = -1;

				restraint[11-1][19-1] = 1;// t11 > t19
				restraint[19-1][11-1] = -1;

				restraint[16-1][20-1] = 1;// t16 > t20
				restraint[20-1][16-1] = -1;
			}
			else
				if (!strcmp(prob,"PTTS40"))//40.12约束陈晓例子
				{
					restraint[2-1][1-1] = 1;// t2 > t1
					restraint[1-1][2-1] = -1;

					restraint[15-1][1-1] = 1;// t15 > t1
					restraint[1-1][15-1] = -1;

					restraint[6-1][3-1] = 1;// t6 > t3
					restraint[3-1][6-1] = -1;

					restraint[11-1][3-1] = 1;// t11 > t3
					restraint[3-1][11-1] = -1;

					restraint[18-1][3-1] = 1;// t18 > t3
					restraint[3-1][18-1] = -1;

					restraint[3-1][4-1] = 1;// t3 > t4
					restraint[4-1][3-1] = -1;

					restraint[14-1][5-1] = 1;// t14 > t5
					restraint[5-1][14-1] = -1;

					restraint[1-1][6-1] = 1;// t1 > t6
					restraint[6-1][1-1] = -1;

					restraint[9-1][6-1] = 1;// t9 > t6
					restraint[6-1][9-1] = -1;

					restraint[19-1][6-1] = 1;// t19 > t6
					restraint[6-1][19-1] = -1;

					restraint[6-1][7-1] = 1;// t6 > t7
					restraint[7-1][6-1] = -1;

					restraint[2-1][9-1] = 1;// t2 > t9
					restraint[9-1][2-1] = -1;

					restraint[14-1][9-1] = 1;// t14 > t9
					restraint[9-1][14-1] = -1;

					restraint[7-1][12-1] = 1;// t7 > t12
					restraint[12-1][7-1] = -1;

					restraint[10-1][12-1] = 1;// t10 > t12
					restraint[12-1][10-1] = -1;

					restraint[19-1][12-1] = 1;// t19 > t12
					restraint[12-1][19-1] = -1;

					restraint[4-1][13-1] = 1;// t4 > t13
					restraint[13-1][4-1] = -1;

					restraint[17-1][13-1] = 1;// t17 > t13
					restraint[13-1][17-1] = -1;

					restraint[14-1][15-1] = 1;// t14 > t15
					restraint[15-1][14-1] = -1;

					restraint[19-1][15-1] = 1;// t19 > t15
					restraint[15-1][19-1] = -1;

					restraint[1-1][17-1] = 1;// t1 > t17
					restraint[17-1][1-1] = -1;

					restraint[9-1][17-1] = 1;// t9 > t17
					restraint[17-1][9-1] = -1;

					restraint[5-1][18-1] = 1;// t5 > t18
					restraint[18-1][5-1] = -1;

					restraint[11-1][19-1] = 1;// t11 > t19
					restraint[19-1][11-1] = -1;

					restraint[16-1][20-1] = 1;// t16 > t20
					restraint[20-1][16-1] = -1;

					/////////////////////////////////////////
					restraint[22-1][1-1] = 1;// t22 > t1
					restraint[1-1][22-1] = -1;

					restraint[35-1][1-1] = 1;// t35 > t1
					restraint[1-1][35-1] = -1;

					restraint[26-1][3-1] = 1;// t26 > t3
					restraint[3-1][26-1] = -1;

					restraint[31-1][3-1] = 1;// t31 > t3
					restraint[3-1][31-1] = -1;

					restraint[38-1][3-1] = 1;// t38 > t3
					restraint[3-1][38-1] = -1;

					restraint[23-1][4-1] = 1;// t23 > t4
					restraint[4-1][23-1] = -1;

					restraint[34-1][5-1] = 1;// t34 > t5
					restraint[5-1][34-1] = -1;

					restraint[21-1][6-1] = 1;// t21 > t6
					restraint[6-1][21-1] = -1;

					restraint[29-1][6-1] = 1;// t29 > t6
					restraint[6-1][29-1] = -1;

					restraint[39-1][6-1] = 1;// t39 > t6
					restraint[6-1][39-1] = -1;

					restraint[26-1][7-1] = 1;// t26 > t7
					restraint[7-1][26-1] = -1;

					restraint[22-1][9-1] = 1;// t22 > t9
					restraint[9-1][22-1] = -1;

					restraint[34-1][9-1] = 1;// t34 > t9
					restraint[9-1][34-1] = -1;

					restraint[27-1][12-1] = 1;// t27 > t12
					restraint[12-1][27-1] = -1;

					restraint[30-1][12-1] = 1;// t30 > t12
					restraint[12-1][30-1] = -1;

					restraint[39-1][12-1] = 1;// t39 > t12
					restraint[12-1][39-1] = -1;

					restraint[24-1][13-1] = 1;// t24 > t13
					restraint[13-1][24-1] = -1;

					restraint[37-1][13-1] = 1;// t37 > t13
					restraint[13-1][37-1] = -1;

					restraint[34-1][15-1] = 1;// t34 > t15
					restraint[15-1][34-1] = -1;

					restraint[39-1][15-1] = 1;// t39 > t15
					restraint[15-1][39-1] = -1;

					restraint[21-1][17-1] = 1;// t21 > t17
					restraint[17-1][21-1] = -1;

					restraint[29-1][17-1] = 1;// t29 > t17
					restraint[17-1][29-1] = -1;

					restraint[25-1][18-1] = 1;// t25 > t18
					restraint[18-1][25-1] = -1;

					restraint[21-1][19-1] = 1;// t21 > t19
					restraint[19-1][21-1] = -1;

					restraint[36-1][20-1] = 1;// t36 > t20
					restraint[20-1][36-1] = -1;
					///////////////////////////////////////////
					restraint[2-1][21-1] = 1;// t2 > t21
					restraint[21-1][2-1] = -1;

					restraint[15-1][21-1] = 1;// t15 > t21
					restraint[21-1][15-1] = -1;

					restraint[6-1][23-1] = 1;// t6 > t23
					restraint[23-1][6-1] = -1;

					restraint[11-1][23-1] = 1;// t11 > t23
					restraint[23-1][11-1] = -1;

					restraint[18-1][23-1] = 1;// t18 > t23
					restraint[23-1][18-1] = -1;

					restraint[3-1][24-1] = 1;// t3 > t24
					restraint[24-1][3-1] = -1;

					restraint[14-1][25-1] = 1;// t14 > t25
					restraint[25-1][14-1] = -1;

					restraint[1-1][26-1] = 1;// t1 > t26
					restraint[26-1][1-1] = -1;

					restraint[9-1][26-1] = 1;// t9 > t26
					restraint[26-1][9-1] = -1;

					restraint[19-1][26-1] = 1;// t19 > t26
					restraint[26-1][19-1] = -1;

					restraint[6-1][27-1] = 1;// t6 > t27
					restraint[27-1][6-1] = -1;

					restraint[2-1][29-1] = 1;// t2 > t29
					restraint[29-1][2-1] = -1;

					restraint[14-1][29-1] = 1;// t14 > t29
					restraint[29-1][14-1] = -1;

					restraint[7-1][32-1] = 1;// t7 > t32
					restraint[32-1][7-1] = -1;

					restraint[10-1][32-1] = 1;// t10 > t32
					restraint[32-1][10-1] = -1;

					restraint[19-1][32-1] = 1;// t19 > t32
					restraint[32-1][19-1] = -1;

					restraint[4-1][33-1] = 1;// t4 > t33
					restraint[33-1][4-1] = -1;

					restraint[17-1][33-1] = 1;// t17 > t33
					restraint[33-1][17-1] = -1;

					restraint[14-1][35-1] = 1;// t14 > t35
					restraint[35-1][14-1] = -1;

					restraint[19-1][35-1] = 1;// t19 > t35
					restraint[35-1][19-1] = -1;

					restraint[1-1][37-1] = 1;// t1 > t37
					restraint[37-1][1-1] = -1;

					restraint[9-1][37-1] = 1;// t9 > t37
					restraint[37-1][9-1] = -1;

					restraint[5-1][38-1] = 1;// t5 > t38
					restraint[38-1][5-1] = -1;

					restraint[11-1][39-1] = 1;// t11 > t39
					restraint[39-1][11-1] = -1;

					restraint[16-1][40-1] = 1;// t16 > t40
					restraint[40-1][16-1] = -1;
					//////////////////////////////////////////
					restraint[22-1][21-1] = 1;// t22 > t21
					restraint[21-1][22-1] = -1;

					restraint[35-1][21-1] = 1;// t35 > t21
					restraint[21-1][35-1] = -1;

					restraint[26-1][23-1] = 1;// t26 > t23
					restraint[23-1][26-1] = -1;

					restraint[31-1][23-1] = 1;// t31 > t23
					restraint[23-1][31-1] = -1;

					restraint[38-1][23-1] = 1;// t38 > t23
					restraint[23-1][38-1] = -1;

					restraint[23-1][24-1] = 1;// t23 > t24
					restraint[24-1][23-1] = -1;

					restraint[34-1][25-1] = 1;// t34 > t25
					restraint[25-1][34-1] = -1;

					restraint[21-1][26-1] = 1;// t21 > t26
					restraint[26-1][21-1] = -1;

					restraint[29-1][26-1] = 1;// t29 > t26
					restraint[26-1][29-1] = -1;

					restraint[39-1][26-1] = 1;// t39 > t26
					restraint[26-1][39-1] = -1;

					restraint[26-1][27-1] = 1;// t26 > t27
					restraint[27-1][26-1] = -1;

					restraint[22-1][29-1] = 1;// t22 > t29
					restraint[29-1][22-1] = -1;

					restraint[34-1][29-1] = 1;// t34 > t29
					restraint[29-1][34-1] = -1;

					restraint[27-1][32-1] = 1;// t27 > t32
					restraint[32-1][27-1] = -1;

					restraint[30-1][32-1] = 1;// t30 > t32
					restraint[32-1][30-1] = -1;

					restraint[39-1][32-1] = 1;// t39 > t32
					restraint[32-1][39-1] = -1;

					restraint[24-1][33-1] = 1;// t24 > t33
					restraint[33-1][24-1] = -1;

					restraint[37-1][33-1] = 1;// t37 > t33
					restraint[33-1][37-1] = -1;

					restraint[34-1][35-1] = 1;// t34 > t35
					restraint[35-1][34-1] = -1;

					restraint[39-1][35-1] = 1;// t39 > t35
					restraint[35-1][39-1] = -1;

					restraint[21-1][37-1] = 1;// t21 > t37
					restraint[37-1][21-1] = -1;

					restraint[29-1][37-1] = 1;// t29 > t37
					restraint[37-1][29-1] = -1;

					restraint[25-1][38-1] = 1;// t25 > t38
					restraint[38-1][25-1] = -1;

					restraint[21-1][39-1] = 1;// t21 > t39
					restraint[39-1][21-1] = -1;

					restraint[36-1][40-1] = 1;// t36 > t40
					restraint[40-1][36-1] = -1;
				}

				//计算完全约束矩阵
				for (rest_i = 0;rest_i<task_num;rest_i++)
					for (rest_j = 0;rest_j<task_num;rest_j++)
						restraint_comp[rest_i][rest_j] = restraint[rest_i][rest_j];//初始化完全约束矩阵

				while (rest_flag)//若完全约束矩阵改变，则继续改变
				{
					rest_flag = 1;
					for (rest_i = 0;rest_i<task_num;rest_i++)
						for (rest_j = 0;rest_j<task_num;rest_j++)//完全约束矩阵改变前先暂存入完全约束矩阵2中						
							restraint_comp2[rest_i][rest_j] = restraint_comp[rest_i][rest_j];

					for (rest_i = 0;rest_i<task_num;rest_i++)
					{
						for (rest_j = 0;rest_j<task_num;rest_j++)//遍历完全约束矩阵						
						{
							if (restraint_comp[rest_i][rest_j] == 1)//将下属约束中的子约束关系加入i的完全约束矩阵中
							{
								for (rest_k = 0;rest_k<task_num;rest_k++)
								{
									if (restraint_comp[rest_j][rest_k] == 1)
									{
										restraint_comp[rest_i][rest_k] = 1;
										restraint_comp[rest_k][rest_i] = -1;
									}
								}
							}
						}
					}
					for (rest_i = 0;rest_i<task_num;rest_i++)
						for (rest_j = 0;rest_j<task_num;rest_j++)
							if (restraint_comp2[rest_i][rest_j] == restraint_comp[rest_i][rest_j])
								rest_flag++;
					if (rest_flag == task_num*task_num + 1)
						rest_flag = 0;

				}//while循环结束时，完全约束矩阵(2)已不再变化
				return;
}