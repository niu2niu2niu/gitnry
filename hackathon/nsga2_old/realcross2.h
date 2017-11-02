/*This is the file used for crossover for Real Coded GA*/

void realcross(population *new_pop_ptr,population *mate_pop_ptr);

void realcross(population *new_pop_ptr,population *mate_pop_ptr)
{
	int i,j,y,n,r;
	float rnd,par1,par2,chld1,chld2,betaq,beta,alpha;
	float y1,y2,yu,yl,expp;

	y=0; n=0;
	for(i = 0; i < popsize/2; i++)
	{    
		if (!strcmp(cross_proba_mod,"random"))
			rnd = randomperc();
		//else
		//	if (!strcmp(cross_proba_mod,"logistic"))
		//		fscanf(logistic_cross_proba_ptr,"%f",&rnd);
		//	else
		//		if (!strcmp(cross_proba_mod,"cat"))
		//			fscanf(cat_cross_proba_ptr,"%f",&rnd);

		/*Check Whether the cross-over to be performed*/
		if(rnd <= pcross)
		{

			/*Loop over no of variables*/
			for(j = 0;j < nvar;j++)
			{ 
				/*Selected Two Parents*/ 
				par1 = mate_pop_ptr->ind[y].xreal[j];
				par2 = mate_pop_ptr->ind[y+1].xreal[j]; 

				yl = lim_r[j][0];
				yu = lim_r[j][1];

				if (!strcmp(cross_mod,"random"))
					rnd = randomperc();
				//else
				// if (!strcmp(cross_mod,"logistic"))
				//  fscanf(logistic_cross_ptr,"%f",&rnd);
				// else
				//  if (!strcmp(cross_mod,"cat"))
				//	  fscanf(cat_cross_ptr,"%f",&rnd);
				if (!strcmp(cross_mod,"logistic"))
				{
					key_lc = logistic_a * key_lc * (1 - key_lc);
					rnd = key_lc;
				}
				if (!strcmp(cross_mod,"cat"))			
				{
					temp_cc = catx_cc;
					catx_cc = catx_cc + caty_cc - floor(catx_cc + caty_cc);//递推公式
					caty_cc = temp_cc + 2 * caty_cc - floor(temp_cc + 2 * caty_cc);
					rnd = catx_cc;
					//rnd = caty_cc;
				}
				if (!strcmp(cross_mod,"ICMIC"))
				{
					//if (ICMICc == 0)
					//	ICMICc = ICMICc + 0.00001;
					ICMICc = sinf(ICMIC_a/ICMICc);
					rnd = (ICMICc+1)/2;
				}
				if (!strcmp(cross_mod,"circle"))			
				{
					circlec = circlec + circle_b - (circle_a/2/pi)*sinf(2*pi*circlec)
						- floor(circlec + circle_b - (circle_a/2/pi)*sinf(2*pi*circlec));
					rnd = circlec;
				}
				if (!strcmp(cross_mod,"bakers"))			
				{
					if (bakers_xc>=0 && bakers_xc<0.5)
					{
						bakers_xc = 2 * bakers_xc;
						bakers_yc = bakers_yc / 2;
					}
					else
					{
						bakers_xc = 2 - 2 * bakers_xc;
						bakers_yc = 1 - bakers_yc / 2;
					}
					rnd = bakers_xc;
				}
				if (!strcmp(cross_mod,"zasla"))			
				{
					zasla_zc = cosf(2*pi*zasla_yc) + exp(-3)*zasla_zc;//递推公式
					zasla_yc = zasla_yc + 400 + 12.6695*zasla_zc
						- floor(zasla_yc + 400 + 12.6695*zasla_zc);
					//rnd = zasla_yc;
					rnd = (zasla_zc + 1.0513)/2.1026;
				}

				/* Check whether variable is selected or not*/
				if(rnd <= 0.5)
				{
					/*Variable selected*/
					ncross++;

					if(fabs(par1 - par2) > 0.000001) // changed by Deb (31/10/01)
					{
						if(par2 > par1) //选择小的par存入y1
						{
							y2 = par2;
							y1 = par1;
						}
						else
						{
							y2 = par1;
							y1 = par2;
						}

						/*Find beta value*/
						if((y1 - yl) > (yu - y2))
						{
							beta = 1 + (2*(yu - y2)/(y2 - y1));
							//printf("beta = %f\n",beta);
						}
						else
						{
							beta = 1 + (2*(y1-yl)/(y2-y1));
							//printf("beta = %f\n",beta);
						}

						/*Find alpha*/
						expp = di + 1.0;

						beta = 1.0/beta;

						alpha = 2.0 - pow(beta,expp);

						if (alpha < 0.0) 
						{
							printf("ERRRROR %f %d %d %f %f\n",alpha,y,n,par1,par2);
							getch();
							exit(-1);
						}

						if (!strcmp(cross_mod,"random"))
							rnd = randomperc();
						//else
						//if (!strcmp(cross_mod,"logistic"))
						// fscanf(logistic_cross_ptr,"%f",&rnd);
						//else
						// if (!strcmp(cross_mod,"cat"))
						//  fscanf(cat_cross_ptr,"%f",&rnd);
						if (!strcmp(cross_mod,"logistic"))
						{
							key_lc = logistic_a * key_lc * (1 - key_lc);
							rnd = key_lc;
						}
						if (!strcmp(cross_mod,"cat"))			
						{
							temp_cc = catx_cc;
							catx_cc = catx_cc + caty_cc - floor(catx_cc + caty_cc);//递推公式
							caty_cc = temp_cc + 2 * caty_cc - floor(temp_cc + 2 * caty_cc);
							rnd = catx_cc;
							//rnd = caty_cc;
						}
						if (!strcmp(cross_mod,"ICMIC"))
						{
							//if (ICMICc == 0)
							//	ICMICc = ICMICc + 0.00001;
							ICMICc = sinf(ICMIC_a/ICMICc);
							rnd = (ICMICc+1)/2;
						}
						if (!strcmp(cross_mod,"circle"))			
						{
							circlec = circlec + circle_b - (circle_a/2/pi)*sinf(2*pi*circlec)
								- floor(circlec + circle_b - (circle_a/2/pi)*sinf(2*pi*circlec));
							rnd = circlec;
						}
						if (!strcmp(cross_mod,"bakers"))			
						{
							if (bakers_xc>=0 && bakers_xc<0.5)
							{
								bakers_xc = 2 * bakers_xc;
								bakers_yc = bakers_yc / 2;
							}
							else
							{
								bakers_xc = 2 - 2 * bakers_xc;
								bakers_yc = 1 - bakers_yc / 2;
							}
							rnd = bakers_xc;
						}
						if (!strcmp(cross_mod,"zasla"))			
						{
							zasla_zc = cosf(2*pi*zasla_yc) + exp(-3)*zasla_zc;//递推公式
							zasla_yc = zasla_yc + 400 + 12.6695*zasla_zc
								- floor(zasla_yc + 400 + 12.6695*zasla_zc);
							//rnd = zasla_yc;
							rnd = (zasla_zc + 1.0513)/2.1026;
						}

						if (rnd <= 1.0/alpha)
						{
							alpha = alpha*rnd;
							expp = 1.0/(di+1.0);
							betaq = pow(alpha,expp);
						}
						else
						{
							alpha = alpha*rnd;
							alpha = 1.0/(2.0-alpha);
							expp = 1.0/(di+1.0);
							if (alpha < 0.0) 
							{
								printf("ERRRORRR \n");
								getch();
								exit(-1);
							}
							betaq = pow(alpha,expp);
						}

						/*Generating two children*/
						chld1 = 0.5*((y1+y2) - betaq*(y2-y1));
						chld2 = 0.5*((y1+y2) + betaq*(y2-y1));

					}
					else //若父代一样
					{

						betaq = 1.0;
						y1 = par1; y2 = par2;

						/*Generation two children*/
						chld1 = 0.5*((y1+y2) - betaq*(y2-y1));//子代1为y1
						chld2 =  0.5*((y1+y2) + betaq*(y2-y1));//子代2为y2

					}
					// added by deb (31/10/01)
					if (chld1 < yl) chld1 = yl;
					if (chld1 > yu) chld1 = yu;
					if (chld2 < yl) chld2 = yl;
					if (chld2 > yu) chld2 = yu;
				}
				else
				{

					/*Copying the children to parents*/
					chld1 = par1;
					chld2 = par2;
				}
				new_pop_ptr->ind[n].xreal[j] = chld1;
				new_pop_ptr->ind[n+1].xreal[j] = chld2;
			}
		}
		else
		{
			for(j = 0;j < nvar;j++)
			{
				par1 = mate_pop_ptr->ind[y].xreal[j];
				par2 = mate_pop_ptr->ind[y+1].xreal[j]; 
				chld1 = par1;
				chld2 = par2;
				new_pop_ptr->ind[n].xreal[j] = chld1;
				new_pop_ptr->ind[n+1].xreal[j] = chld2;
			}
		}
		n = n+2; y=y+2;
	}	
	return;
}