/*This is the program used to evaluate the value of the function & errors
************************************************************************/
void func(population *pop_ptr);

void func(population *pop_ptr)
{
	/*File ptr to the file to store the value of the g for last iteration
	g is the parameter required for a particular problem
	Every problem is not required*/

	float *realx_ptr, /*Pointer to the array of x values*/
		*binx_ptr,      /* Pointer to the binary variables */
		*fitn_ptr,      /*Pointer to the array of fitness function*/
		x[2*maxvar],     /* problem variables */
		f[maxfun],     /*array of fitness values*/
		*err_ptr,      /*Pointer to the error */
		cstr[maxcons];

	int i,j,k,x_i,x_j,chri_i,chri_j,chri_k,r_i,r_j,r_k; 
	float sum_x=0,g_x=0;
	float error, cc;

	int m_amount_based_on_t[task_num];//��Ŷ�Ӧ�������еķ�����ѡ����
	int parallel_r[4*task_num] = {0};//��������μ�matlab����
	int r[4*task_num] = {0};
	int r_constraint = 0;
	int start = 0;
	int lmd[task_num] = {0};
	int K = 0;//��ʼ�����в���
	int time[task_num] = {0};
	int r_time[4*task_num] = {0};
	int parallel_time[task_num] = {0};
	int parallel_instrument[task_num] = {0};
	int parallel_time_max[task_num] = {0};
	int max_r_time = 0;
	int t_13_index=0,t_6_index=0,t_4_index=0,t_10_index=0;
	int t_28_index=0,t_21_index=0,t_19_index=0,t_25_index=0;

	int t_time[task_num] = {0};//��ʼ����¼����ʼʱ�������,��������������
	int t_index[task_num] = {0};//��1~task_num��������Ⱦɫ���е��±��¼��t_index������

	int dag[task_num][task_num+1] = {0};//���������޻�ͼDAG��Ϊ��������׼��
	int zero_indegree[task_num] = {0};//������Ϊ0��������

	pop_ptr->ind_ptr= &(pop_ptr->ind[0]);

	/*Initializing the max rank to zero*/
	pop_ptr->maxrank = 0;
	for(i = 0;i < popsize;i++)
	{
		pop_ptr->ind_ptr = &(pop_ptr->ind[i]);
		realx_ptr = &(pop_ptr->ind_ptr->xreal[0]);
		binx_ptr = &(pop_ptr->ind_ptr->xbin[0]);

		for(j = 0; j < nvar; j++)
		{ // Real-coded variables 
			x[j] = *realx_ptr++;
		}

		for(j = 0; j < nchrom; j++)
		{ // Binary-codced variables
			x[nvar+j] = *binx_ptr++;
		}

		fitn_ptr = &(pop_ptr->ind_ptr->fitness[0]);
		err_ptr = &(pop_ptr->ind_ptr->error);

		/*   DO NOT CHANGE ANYTHING ABOVE   */
		/*----------------------CODE YOUR OBJECTIVE FUNCTIONS HERE------------*/
		/*All functions must be of minimization type, negate maximization
		functions */
		/*============Start Coding Your Function From This Point=============*/

		if (!strcmp(prob,"ZDT1"))
		{
			// First fitness function
			f[0] = x[0];
			// Second Fitness Function
			sum_x = 0;
			for (x_i = 1;x_i < nvar;x_i++)
				sum_x = sum_x + x[x_i];

			g_x = 1 + 9*sum_x/(nvar-1);
			f[1] = g_x*(1-(sqrt(x[0]/g_x)));
		}
		else
			if(!strcmp(prob,"ZDT2"))
			{
				f[0] = x[0];
				sum_x = 0;
				for (x_i = 1;x_i < nvar;x_i++)
					sum_x = sum_x + x[x_i];

				g_x = 1 + 9*sum_x/(nvar-1);
				f[1] = g_x*(1-pow((x[0]/g_x),2));
			}
			else
				if(!strcmp(prob,"ZDT3"))
				{
					f[0] = x[0];
					sum_x = 0;
					for (x_i = 1;x_i < nvar;x_i++)
						sum_x = sum_x + x[x_i];

					g_x = 1 + 9*sum_x/(nvar-1);
					f[1] = g_x*(1-sqrt(x[0]/g_x)-(x[0]/g_x)*sinf(10*pi*x[0]));
				}
				else
					if(!strcmp(prob,"ZDT4"))
					{
						f[0] = x[0];
						sum_x = 0;
						for (x_i = 1;x_i < nvar;x_i++)
							sum_x = sum_x + pow(x[x_i],2) - 10*cosf(4*pi*x[x_i]);

						g_x = 1 + 10 * (nvar-1) + sum_x;
						f[1] = g_x*(1-sqrt(x[0]/g_x));
					}
					else
						if(!strcmp(prob,"ZDT6"))
						{
							f[0] = 1-exp(-4*x[0])*pow(sinf(6*pi*x[0]),6);
							sum_x = 0;
							for (x_i = 1;x_i < nvar;x_i++)
								sum_x = sum_x + x[x_i];

							g_x = 1 + 9 * pow(sum_x/(nvar-1),0.25);
							f[1] = g_x*(1-pow((f[0]/g_x),2));
						}
						else
							if (!strcmp(prob,"PTTS")||!strcmp(prob,"PTTS40"))
							{
								f[0] = 0;
								f[1] = 0;
								r_constraint = 0;
								start = 0;
								K = 0;
								max_r_time = 0;
								for (x_i = 0;x_i < 4*task_num;x_i++)
								{
									parallel_r[x_i] = 0;//��������μ�matlab����
									r[x_i] = 0;
									r_time[x_i] = 0;
								}
								for (x_i = 0;x_i < task_num;x_i++)
								{
									lmd[x_i] = 0;
									time[x_i] = 0;
									parallel_time[x_i] = 0;
									parallel_instrument[x_i] = 0;
									parallel_time_max[x_i] = 0;
									t_time[x_i] = 0;
								}
								for (x_i = 0;x_i < task_num;x_i++)//��ʼ��ͼΪ��ͼ
								{
									for (x_j = 0;x_j < task_num+1;x_j++)
									{
										dag[x_i][x_j] = 0;
									}
								}
								for (x_i = 0;x_i < task_num;x_i++)//��ʼ��ͼΪԼ��ͼ
								{
									for (x_j = 0;x_j < task_num;x_j++)
									{
										dag[x_i][x_j] = restraint_comp[x_i][x_j];
										if (dag[x_i][x_j] == -1)
										{
											dag[x_i][task_num]++;
										}
									}
								}
								/******����*******/
								//x[0] = 0.66666;
								//x[1] = 0.22222;
								//x[2] = 0.33333;
								//x[3] = 0.44444;
								//x[4] = 0.11111;
								//x[5] = 0.23558;

								//��ʼ��
								for (chri_i=0;chri_i<task_num;chri_i++)
								{
									chri.t[chri_i] = 1;
									chri.m[chri_i] = 0;
								}

								//�õ���������
								//for (chri_i=0;chri_i<task_num;chri_i++)
								//	for (chri_j=0;chri_j<task_num;chri_j++)
								//		if (x[chri_j]<x[chri_i])
								//			chri.t[chri_i]++;//chri.t�зŵ��������
								for (chri_i=0;chri_i<task_num;chri_i++)//����������
								{
									x_j = 0;//����zero_indegree�����±�
									for (x_i = 0;x_i < task_num;x_i++)
									{
										if (dag[x_i][task_num] == 0)//��¼���Ϊ0�������ŵ�zero_indegree
										{
											zero_indegree[x_j] = x_i;
											x_j++;
										}
									}
									chri.t[chri_i] = zero_indegree[0];//�Ƚ���һ�����Ϊ0������ŵ���λ��
									for (x_i = 0;x_i < x_j;x_i++)//����zero_indegree����
									{
										if (x[zero_indegree[x_i]] > x[chri.t[chri_i]])
										{
											//��Ȩֵ��ߵ����Ϊ0������ŵ���λ��
											chri.t[chri_i] = zero_indegree[x_i];
										}
									}
									dag[chri.t[chri_i]][task_num]--;
									for (x_i = 0;x_i < task_num;x_i++)
									{
										if (dag[x_i][chri.t[chri_i]] == -1)
											dag[x_i][task_num]--;
									}
								}
								for (chri_i=0;chri_i<task_num;chri_i++)
									chri.t[chri_i]++;

								//�õ�������
								for (chri_i=0;chri_i<task_num;chri_i++)
								{
									chri_k = 1;
									while (meth[chri.t[chri_i]].m[chri_k])
									{
										chri_k++;
									}
									m_amount_based_on_t[chri_i] = chri_k-1;
									chri.m[chri_i] = (int)(x[chri_i]*10)%m_amount_based_on_t[chri_i]+1;
								}

								/*chri.t[0] = 1;
								chri.t[1] = 2;
								chri.t[2] = 3;
								chri.t[3] = 4;
								chri.t[4] = 5;
								chri.t[5] = 6;

								chri.m[0] = 1;
								chri.m[1] = 1;
								chri.m[2] = 1;
								chri.m[3] = 1;
								chri.m[4] = 1;
								chri.m[5] = 1;

								/********��Ŀ�꺯��*********/
								for (chri_i=0;chri_i<task_num;chri_i++)//������������
								{
									//�Ȱ�����Դ��ͻ��������ʼʱ��	
									chri_k = 0;
									max_r_time = 0;
									while (meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1])//����Դ��ռ�õ����ʱ��
									{											  
										if (max_r_time < r_time[meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1]])
											max_r_time = r_time[meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1]];
										chri_k++;
									}
									t_time[chri.t[chri_i]-1] =max_r_time;

									//�ٰ���Լ����������ʼʱ��
									for (chri_j=0;chri_j<chri_i+1;chri_j++)//������i������֮ǰ������
										//������Լ����ϵ����Ŀǰ�Ŀ�ʼʱ��ȴ���Լ����ϵ����������ʱ��̣�
										//�򽫸�����Ŀ�ʼʱ�����Ϊ����Լ����ϵ����������ʱ��
									{
										if (restraint_comp[chri.t[chri_i]-1][chri.t[chri_j]-1]!=0 &&
											t_time[chri.t[chri_i]-1] < t_time[chri.t[chri_j]-1] + meth[chri.t[chri_j]].time[chri.m[chri_j]])
										{
											t_time[chri.t[chri_i]-1] = t_time[chri.t[chri_j]-1] + meth[chri.t[chri_j]].time[chri.m[chri_j]];
										}
									}

									//���㲢�в���
									chri_k = 0;
									for (chri_j=0;chri_j<chri_i+1;chri_j++)//������i������֮ǰ������
									{
										if (t_time[chri.t[chri_j]-1] != t_time[chri.t[chri_i]-1])
											chri_k++;
									}
									if (chri_k == chri_i)//���������i֮ǰ������������û�к��俪ʼʱ����ͬ���������в�����1
										K++;									

									//��������ʱ��
									chri_j = 0;
									while (meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_j+1])
									{
										r_time[meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_j+1]]
										=t_time[chri.t[chri_i]-1] + meth[chri.t[chri_i]].time[chri.m[chri_i]];
										chri_j++;
									}
								}

								//Ŀ�꺯��1���������ռ��ʱ�䣬������ʱ��
								//f[0] = 0;
								f[0] = r_time[0];
								for (chri_k=0;chri_k<4*task_num;chri_k++)
									if (f[0] < r_time[chri_k])
										f[0] = r_time[chri_k];

								//Ŀ�꺯��2Ϊ���л����ĸ���ƽ��������С
								//f[1] = 0;																
								//for (chri_i=0;chri_i<task_num;chri_i++)
								//{
								//	//��¼����ռ����Դ����
								//	chri_k = 0;
								//	while (meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1])
								//		chri_k++;
								//	//�����ܸ���
								//	parallel_time[0] = parallel_time[0] + meth[chri.t[chri_i]].time[chri.m[chri_i]]*(chri_k);
								//}
								//f[1] = parallel_time[0] / (float)K;//�������ƽ������

								//Ŀ�꺯��3��Լ��Υ������
								f[1] = 0;//��ʼ��Լ��Υ������
								for (chri_i=0;chri_i<task_num;chri_i++)//������������
								{
									for (chri_j=0;chri_j<task_num;chri_j++)//����Ⱦɫ���t����
									{
										if (chri.t[chri_j] == (chri_i + 1))//���ҵ�����i��λ�ã����¼���±�
										{
											t_index[chri_i] = chri_j;
										}
									}
								}
								for (chri_i=0;chri_i<task_num;chri_i++)
								{
									for (chri_j=0;chri_j<task_num;chri_j++)//������ȫԼ������
									{
										//������i>����j��������i���±�������j֮����˵��Υ����һ��Լ����ϵ
										if (restraint_comp[chri_i][chri_j] == 1 && t_index[chri_i] > t_index[chri_j])
										{
											f[1]++;
										}
									}
								}

							}//����PTTS����

							else
								if (!strcmp(prob,"PTTS2"))
								{
									f[0] = 0;
									f[1] = 0;
									r_constraint = 0;
									start = 0;
									K = 0;
									max_r_time = 0;
									for (x_i = 0;x_i < 4*task_num;x_i++)
									{
										parallel_r[x_i] = 0;//��������μ�matlab����
										r[x_i] = 0;
										r_time[x_i] = 0;
									}
									for (x_i = 0;x_i < task_num;x_i++)
									{
										lmd[x_i] = 0;
										time[x_i] = 0;
										parallel_time[x_i] = 0;
										parallel_instrument[x_i] = 0;
										parallel_time_max[x_i] = 0;

									}
									/******����*******/
									//��ʼ��
									for (chri_i=0;chri_i<task_num;chri_i++)
									{
										chri.t[chri_i] = 1;
										chri.m[chri_i] = 0;
									}
									//�õ���������
									for (chri_i=0;chri_i<task_num;chri_i++)
										for (chri_j=0;chri_j<task_num;chri_j++)
											if (x[chri_j]<x[chri_i])
												chri.t[chri_i]++;//chri.t�зŵ��������
									//�õ�������
									for (chri_i=0;chri_i<task_num;chri_i++)
									{
										chri_k = 1;
										while (meth[chri.t[chri_i]].m[chri_k])
										{
											chri_k++;
										}
										m_amount_based_on_t[chri_i] = chri_k-1;
										chri.m[chri_i] = (int)(x[chri_i]*10)%m_amount_based_on_t[chri_i]+1;
									}

									/********��Ŀ�꺯��*********/
									for (r_i=0;r_i<4;r_i++)
										parallel_r[r_i-1] = meth[chri.t[0]].r[chri.m[0]][r_i];//��¼��һ�����������õ�������
									//��ʼѭ��
									for (chri_i=1;chri_i<task_num;chri_i++)
									{
										r_constraint = 0;
										//�Ժ�������õ���������ʱ��¼��r��
										for (r_i=0;r_i<4;r_i++)
											r[r_i-1] = meth[chri.t[chri_i]].r[chri.m[chri_i]][r_i];
										//�ж�r���Ƿ���Ԫ���Ѿ���parallel_r�д���
										for (r_j=0;r_j<4*task_num;r_j++)
											for (r_k=0;r_k<4*task_num;r_k++)
												if (parallel_r[r_j] == r[r_k] && parallel_r[r_j]!=0)
													r_constraint = 1;//���ɲ���
										//��r��parallel_rû����ͬԪ�أ��ɲ���
										if (!r_constraint)
										{
											r_i = 0;
											r_j = 0;
											r_k = 0;
											while (parallel_r[r_i])
												r_i++;
											//���ɲ�����Դ�ϲ�
											while (r[r_j])
											{
												parallel_r[r_i] = r[r_j];
												r_i++;
												r_j++;
											}
										}
										//�����ɲ���
										else
										{
											K++;
											for (chri_j=start;chri_j<=chri_i-1;chri_j++)
											{
												time[chri_j] = meth[chri.t[chri_j]].time[chri.m[chri_j]];
												chri_k = 0;
												max_r_time = 0;
												//����Դ��ռ�õ����ʱ��
												while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
												{											  
													if (max_r_time < r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]])
														max_r_time = r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]];
													chri_k++;
												}
												//��������ʱ��
												chri_k = 0;
												while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
												{
													r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]]
													=max_r_time + meth[chri.t[chri_j]].time[chri.m[chri_j]];
													chri_k++;
												}
												//��¼����ռ����Դ����
												chri_k = 0;
												while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
													chri_k++;
												//���ֲ�����ʱ��
												parallel_time[K-1] = parallel_time[K-1] + time[chri_j]*(chri_k);
												//���ֲ���������
												parallel_instrument[K-1] = parallel_instrument[K-1] + (chri_k);
											}
											lmd[K-1] = chri_i - start;//��¼ÿ�ֲ���������������lmd
											//��¼ÿ�ֲ��н�ֹʱ��,��r_time�����ֵ
											parallel_time_max[K-1] = r_time[0];
											for (chri_k=0;chri_k<4*task_num;chri_k++)
												if (parallel_time_max[K-1] < r_time[chri_k])
													parallel_time_max[K-1] = r_time[chri_k];
											//ʱ������
											for (chri_k=0;chri_k<task_num;chri_k++)
												time[chri_k] = 0;
											//����������������
											for (chri_k=0;chri_k<4*task_num;chri_k++)
												parallel_r[chri_k] = 0;
											for (r_i=0;r_i<4;r_i++)
												parallel_r[r_i] = r[r_i];
											//�������ֲ��п�ʼ�±�
											start = chri_i;
										}//����else

									}//�������������
									/****����ѭ����ļ�¼****/
									K++;
									for (chri_j=start;chri_j<chri_i;chri_j++)
									{
										time[chri_j] = meth[chri.t[chri_j]].time[chri.m[chri_j]];
										chri_k = 0;
										max_r_time = 0;
										//����Դ��ռ�õ����ʱ��
										while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
										{											  
											if (max_r_time < r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]])
												max_r_time = r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]];
											chri_k++;
										}
										//��������ʱ��
										chri_k = 0;
										while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
										{
											r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]]
											=max_r_time + meth[chri.t[chri_j]].time[chri.m[chri_j]];
											chri_k++;
										}
										//��¼����ռ����Դ����
										chri_k = 0;
										while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
											chri_k++;
										//���ֲ�����ʱ��
										parallel_time[K-1] = parallel_time[K-1] + time[chri_j]*(chri_k);
										//���ֲ���������
										parallel_instrument[K-1] = parallel_instrument[K-1] + (chri_k);
									}
									lmd[K-1] = chri_i - start;

									//Ŀ�꺯��1���������ռ��ʱ�䣬������ʱ��
									f[0] = r_time[0];
									for (chri_k=0;chri_k<4*task_num;chri_k++)
										if (f[0] < r_time[chri_k])
											f[0] = r_time[chri_k];

									//Ŀ�꺯��2Ϊ���л����ĸ���ƽ��������С
									f[1] = 0;
									/*for (chri_i=0;chri_i<task_num;chri_i++)
									f[1] = f[1] + parallel_time[chri_i];

									f[1] = f[1]/K;*/
									for (chri_i=0;chri_i<task_num;chri_i++)
									{
										if (chri.t[chri_i]==4)
											t_4_index = chri_i;
										if (chri.t[chri_i]==6)
											t_6_index = chri_i;
										if (chri.t[chri_i]==10)
											t_10_index = chri_i;
										if (chri.t[chri_i]==13)
											t_13_index = chri_i;

										if (chri.t[chri_i]==19)
											t_19_index = chri_i;
										if (chri.t[chri_i]==21)
											t_21_index = chri_i;
										if (chri.t[chri_i]==25)
											t_25_index = chri_i;
										if (chri.t[chri_i]==28)
											t_28_index = chri_i;
									}
									if (t_13_index>t_6_index)
										f[1]++;
									if (t_4_index>t_10_index)
										f[1]++;

									if (t_28_index>t_21_index)
										f[1]++;
									if (t_19_index>t_25_index)
										f[1]++;

								}//����PTTS����

								/*=========End Your Coding Upto This Point===============*/
								/******************************************************************/
								/*              Put The Constraints Here                          */
								/******************************************************************/
								// g(x) >= 0 type (normalize g(x) as in the cstr[1] below)
								/*===========Start Coding Here=============*/
								/*   cstr[0] = x[0]*x[0]+x[1]*x[1]-1.0-0.1*cos(16.0*atan(x[0]/x[1]));
								cstr[1] = (-square(x[0]-0.5) - square(x[1]-0.5) + 0.5)/0.5;*/
								/*===========Constraints Are Coded Upto Here=============*/
								/*   DO NOT CHANGE ANYTHING BELOW  */

								for(k = 0 ; k < nfunc ;k++)
								{
									*fitn_ptr++  = f[k];
								}

								for (k = 0;k < ncons; k++)
								{
									pop_ptr->ind_ptr->constr[k] = cstr[k];
								}
								error = 0.0;
								for (k = 0;k < ncons;k++)
								{
									cc = cstr[k];
									if(cc < 0.0)
										error = error - cc;
								}
								*err_ptr = error;
	}

	/*---------------------------* RANKING *------------------------------*/

	if(ncons == 0)
		ranking(pop_ptr);
	else
		rankcon(pop_ptr);

	return;
}