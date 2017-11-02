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

	int m_amount_based_on_t[task_num];//存放对应任务序列的方案可选总数
	int parallel_r[4*task_num] = {0};//变量含义参见matlab程序
	int r[4*task_num] = {0};
	int r_constraint = 0;
	int start = 0;
	int lmd[task_num] = {0};
	int K = 0;//初始化并行步数
	int time[task_num] = {0};
	int r_time[4*task_num] = {0};
	int parallel_time[task_num] = {0};
	int parallel_instrument[task_num] = {0};
	int parallel_time_max[task_num] = {0};
	int max_r_time = 0;
	int t_13_index=0,t_6_index=0,t_4_index=0,t_10_index=0;
	int t_28_index=0,t_21_index=0,t_19_index=0,t_25_index=0;

	int t_time[task_num] = {0};//初始化记录任务开始时间的数组,数组的列是任务号
	int t_index[task_num] = {0};//将1~task_num个任务在染色体中的下标记录在t_index数组中

	int dag[task_num][task_num+1] = {0};//定义有向无环图DAG，为拓扑排序准备
	int zero_indegree[task_num] = {0};//存放入度为0的任务编号

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
									parallel_r[x_i] = 0;//变量含义参见matlab程序
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
								for (x_i = 0;x_i < task_num;x_i++)//初始化图为空图
								{
									for (x_j = 0;x_j < task_num+1;x_j++)
									{
										dag[x_i][x_j] = 0;
									}
								}
								for (x_i = 0;x_i < task_num;x_i++)//初始化图为约束图
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
								/******解码*******/
								//x[0] = 0.66666;
								//x[1] = 0.22222;
								//x[2] = 0.33333;
								//x[3] = 0.44444;
								//x[4] = 0.11111;
								//x[5] = 0.23558;

								//初始化
								for (chri_i=0;chri_i<task_num;chri_i++)
								{
									chri.t[chri_i] = 1;
									chri.m[chri_i] = 0;
								}

								//得到任务序列
								//for (chri_i=0;chri_i<task_num;chri_i++)
								//	for (chri_j=0;chri_j<task_num;chri_j++)
								//		if (x[chri_j]<x[chri_i])
								//			chri.t[chri_i]++;//chri.t中放的是任务号
								for (chri_i=0;chri_i<task_num;chri_i++)//求任务序列
								{
									x_j = 0;//设置zero_indegree数组下标
									for (x_i = 0;x_i < task_num;x_i++)
									{
										if (dag[x_i][task_num] == 0)//记录入度为0的任务编号到zero_indegree
										{
											zero_indegree[x_j] = x_i;
											x_j++;
										}
									}
									chri.t[chri_i] = zero_indegree[0];//先将第一个入度为0的任务放到该位置
									for (x_i = 0;x_i < x_j;x_i++)//遍历zero_indegree数组
									{
										if (x[zero_indegree[x_i]] > x[chri.t[chri_i]])
										{
											//将权值最高的入度为0的任务放到该位置
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

								//得到方案号
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

								/********求目标函数*********/
								for (chri_i=0;chri_i<task_num;chri_i++)//遍历所有任务
								{
									//先按照资源冲突设置任务开始时间	
									chri_k = 0;
									max_r_time = 0;
									while (meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1])//求资源被占用的最大时间
									{											  
										if (max_r_time < r_time[meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1]])
											max_r_time = r_time[meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1]];
										chri_k++;
									}
									t_time[chri.t[chri_i]-1] =max_r_time;

									//再按照约束设置任务开始时间
									for (chri_j=0;chri_j<chri_i+1;chri_j++)//遍历第i个任务之前的任务
										//若存在约束关系，且目前的开始时间比存在约束关系的任务的完成时间短，
										//则将该任务的开始时间更新为存在约束关系的任务的完成时间
									{
										if (restraint_comp[chri.t[chri_i]-1][chri.t[chri_j]-1]!=0 &&
											t_time[chri.t[chri_i]-1] < t_time[chri.t[chri_j]-1] + meth[chri.t[chri_j]].time[chri.m[chri_j]])
										{
											t_time[chri.t[chri_i]-1] = t_time[chri.t[chri_j]-1] + meth[chri.t[chri_j]].time[chri.m[chri_j]];
										}
									}

									//计算并行步数
									chri_k = 0;
									for (chri_j=0;chri_j<chri_i+1;chri_j++)//遍历第i个任务之前的任务
									{
										if (t_time[chri.t[chri_j]-1] != t_time[chri.t[chri_i]-1])
											chri_k++;
									}
									if (chri_k == chri_i)//如果在任务i之前的所有任务中没有和其开始时间相同的任务，则并行步数加1
										K++;									

									//修正仪器时间
									chri_j = 0;
									while (meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_j+1])
									{
										r_time[meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_j+1]]
										=t_time[chri.t[chri_i]-1] + meth[chri.t[chri_i]].time[chri.m[chri_i]];
										chri_j++;
									}
								}

								//目标函数1是最大仪器占用时间，即测试时间
								//f[0] = 0;
								f[0] = r_time[0];
								for (chri_k=0;chri_k<4*task_num;chri_k++)
									if (f[0] < r_time[chri_k])
										f[0] = r_time[chri_k];

								//目标函数2为所有机器的各步平均负荷最小
								//f[1] = 0;																
								//for (chri_i=0;chri_i<task_num;chri_i++)
								//{
								//	//记录任务占用资源总数
								//	chri_k = 0;
								//	while (meth[chri.t[chri_i]].r[chri.m[chri_i]][chri_k+1])
								//		chri_k++;
								//	//计算总负载
								//	parallel_time[0] = parallel_time[0] + meth[chri.t[chri_i]].time[chri.m[chri_i]]*(chri_k);
								//}
								//f[1] = parallel_time[0] / (float)K;//计算各步平均负载

								//目标函数3是约束违反个数
								f[1] = 0;//初始化约束违反个数
								for (chri_i=0;chri_i<task_num;chri_i++)//遍历所有任务
								{
									for (chri_j=0;chri_j<task_num;chri_j++)//遍历染色体的t数组
									{
										if (chri.t[chri_j] == (chri_i + 1))//若找到任务i的位置，则记录其下标
										{
											t_index[chri_i] = chri_j;
										}
									}
								}
								for (chri_i=0;chri_i<task_num;chri_i++)
								{
									for (chri_j=0;chri_j<task_num;chri_j++)//遍历完全约束矩阵
									{
										//若任务i>任务j，且任务i的下标在任务j之后，则说明违反了一条约束关系
										if (restraint_comp[chri_i][chri_j] == 1 && t_index[chri_i] > t_index[chri_j])
										{
											f[1]++;
										}
									}
								}

							}//结束PTTS问题

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
										parallel_r[x_i] = 0;//变量含义参见matlab程序
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
									/******解码*******/
									//初始化
									for (chri_i=0;chri_i<task_num;chri_i++)
									{
										chri.t[chri_i] = 1;
										chri.m[chri_i] = 0;
									}
									//得到任务序列
									for (chri_i=0;chri_i<task_num;chri_i++)
										for (chri_j=0;chri_j<task_num;chri_j++)
											if (x[chri_j]<x[chri_i])
												chri.t[chri_i]++;//chri.t中放的是任务号
									//得到方案号
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

									/********求目标函数*********/
									for (r_i=0;r_i<4;r_i++)
										parallel_r[r_i-1] = meth[chri.t[0]].r[chri.m[0]][r_i];//记录第一个测试任务用到的仪器
									//开始循环
									for (chri_i=1;chri_i<task_num;chri_i++)
									{
										r_constraint = 0;
										//以后的任务用到的仪器暂时记录在r中
										for (r_i=0;r_i<4;r_i++)
											r[r_i-1] = meth[chri.t[chri_i]].r[chri.m[chri_i]][r_i];
										//判断r中是否有元素已经中parallel_r中存在
										for (r_j=0;r_j<4*task_num;r_j++)
											for (r_k=0;r_k<4*task_num;r_k++)
												if (parallel_r[r_j] == r[r_k] && parallel_r[r_j]!=0)
													r_constraint = 1;//不可并行
										//若r和parallel_r没有相同元素，可并行
										if (!r_constraint)
										{
											r_i = 0;
											r_j = 0;
											r_k = 0;
											while (parallel_r[r_i])
												r_i++;
											//将可并行资源合并
											while (r[r_j])
											{
												parallel_r[r_i] = r[r_j];
												r_i++;
												r_j++;
											}
										}
										//若不可并行
										else
										{
											K++;
											for (chri_j=start;chri_j<=chri_i-1;chri_j++)
											{
												time[chri_j] = meth[chri.t[chri_j]].time[chri.m[chri_j]];
												chri_k = 0;
												max_r_time = 0;
												//求资源被占用的最大时间
												while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
												{											  
													if (max_r_time < r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]])
														max_r_time = r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]];
													chri_k++;
												}
												//修正仪器时间
												chri_k = 0;
												while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
												{
													r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]]
													=max_r_time + meth[chri.t[chri_j]].time[chri.m[chri_j]];
													chri_k++;
												}
												//记录任务占用资源总数
												chri_k = 0;
												while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
													chri_k++;
												//本轮并行总时间
												parallel_time[K-1] = parallel_time[K-1] + time[chri_j]*(chri_k);
												//本轮并行仪器数
												parallel_instrument[K-1] = parallel_instrument[K-1] + (chri_k);
											}
											lmd[K-1] = chri_i - start;//记录每轮并行任务数到数组lmd
											//记录每轮并行截止时间,是r_time的最大值
											parallel_time_max[K-1] = r_time[0];
											for (chri_k=0;chri_k<4*task_num;chri_k++)
												if (parallel_time_max[K-1] < r_time[chri_k])
													parallel_time_max[K-1] = r_time[chri_k];
											//时间清零
											for (chri_k=0;chri_k<task_num;chri_k++)
												time[chri_k] = 0;
											//修正并行仪器数组
											for (chri_k=0;chri_k<4*task_num;chri_k++)
												parallel_r[chri_k] = 0;
											for (r_i=0;r_i<4;r_i++)
												parallel_r[r_i] = r[r_i];
											//修正本轮并行开始下标
											start = chri_i;
										}//结束else

									}//结束按任务遍历
									/****跳出循环后的记录****/
									K++;
									for (chri_j=start;chri_j<chri_i;chri_j++)
									{
										time[chri_j] = meth[chri.t[chri_j]].time[chri.m[chri_j]];
										chri_k = 0;
										max_r_time = 0;
										//求资源被占用的最大时间
										while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
										{											  
											if (max_r_time < r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]])
												max_r_time = r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]];
											chri_k++;
										}
										//修正仪器时间
										chri_k = 0;
										while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
										{
											r_time[meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1]]
											=max_r_time + meth[chri.t[chri_j]].time[chri.m[chri_j]];
											chri_k++;
										}
										//记录任务占用资源总数
										chri_k = 0;
										while (meth[chri.t[chri_j]].r[chri.m[chri_j]][chri_k+1])
											chri_k++;
										//本轮并行总时间
										parallel_time[K-1] = parallel_time[K-1] + time[chri_j]*(chri_k);
										//本轮并行仪器数
										parallel_instrument[K-1] = parallel_instrument[K-1] + (chri_k);
									}
									lmd[K-1] = chri_i - start;

									//目标函数1是最大仪器占用时间，即测试时间
									f[0] = r_time[0];
									for (chri_k=0;chri_k<4*task_num;chri_k++)
										if (f[0] < r_time[chri_k])
											f[0] = r_time[chri_k];

									//目标函数2为所有机器的各步平均负荷最小
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

								}//结束PTTS问题

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