/* This is the module used to formulate the mutation routine*/

void real_mutate(population *new_pop_ptr);             

void real_mutate(population *new_pop_ptr)
{
	int i,j,r;
	float rnd,delta,indi,*ptr,*ptr1,deltaq;
	float y,yl,yu,val,xy;  

	for(j = 0;j < popsize;j++)
	{
		for (i = 0;i < nvar; i++)
		{

			if (!strcmp(mutation_proba_mod,"random"))
				rnd = randomperc();
			//else
			//	if (!strcmp(mutation_proba_mod,"logistic"))
			//		fscanf(logistic_mut_proba_ptr,"%f",&rnd);
			//	else
			//		if (!strcmp(mutation_proba_mod,"cat"))
			//			fscanf(cat_mut_proba_ptr,"%f",&rnd);

			/*For each variable find whether to do mutation or not*/
			if(rnd <= pmut_r)
			{
				y = new_pop_ptr->ind[j].xreal[i];
				yl = lim_r[i][0];
				yu = lim_r[i][1];

				if(y > yl)
				{
					/*Calculate delta*/

					if((y-yl) < (yu-y))
						delta = (y - yl)/(yu - yl);
					else
						delta = (yu - y)/(yu-yl);

					if (!strcmp(mutation_mod,"random"))
						rnd = randomperc();
					//else
					//	if (!strcmp(mutation_mod,"logistic"))
					//		fscanf(logistic_mut_ptr,"%f",&rnd);
					//	else
					//		if (!strcmp(mutation_mod,"cat"))
					//			fscanf(cat_mut_ptr,"%f",&rnd);
					if (!strcmp(mutation_mod,"logistic"))
					{
						key_lm = logistic_a * key_lm * (1 - key_lm);
						rnd = key_lm;
					}
					if (!strcmp(mutation_mod,"cat"))			
					{
						temp_cm = catx_cm;
						catx_cm = catx_cm + caty_cm - floor(catx_cm + caty_cm);//递推公式
						caty_cm = temp_cm + 2 * caty_cm - floor(temp_cm + 2 * caty_cm);
						rnd = catx_cm;
						//rnd = caty_cm;
					}
					if (!strcmp(mutation_mod,"ICMIC"))
					{
						//if (ICMICm == 0)
						//	ICMICm = ICMICm + 0.00001;
						ICMICm = sinf(ICMIC_a/ICMICm);
						rnd = (ICMICm+1)/2;
					}
					if (!strcmp(mutation_mod,"circle"))			
					{
						circlem = circlem + circle_b - (circle_a/2/pi)*sinf(2*pi*circlem)
							- floor(circlem + circle_b - (circle_a/2/pi)*sinf(2*pi*circlem));
						rnd = circlem;
					}
					if (!strcmp(mutation_mod,"bakers"))			
					{
						if (bakers_xm>=0 && bakers_xm<0.5)
						{
							bakers_xm = 2 * bakers_xm;
							bakers_ym = bakers_ym / 2;
						}
						else
						{
							bakers_xm = 2 - 2 * bakers_xm;
							bakers_ym = 1 - bakers_ym / 2;
						}
						rnd = bakers_xm;
					}
					if (!strcmp(mutation_mod,"zasla"))			
					{
						zasla_zm = cosf(2*pi*zasla_ym) + exp(-3)*zasla_zm;//递推公式
						zasla_ym = zasla_ym + 400 + 12.6695*zasla_zm
							- floor(zasla_ym + 400 + 12.6695*zasla_zm);
						//rnd = zasla_ym;
						rnd = (zasla_zm + 1.0513)/2.1026;
					}

					indi = 1.0/(dim +1.0);

					if(rnd <= 0.5)
					{
						xy = 1.0-delta;
						val = 2*rnd+(1-2*rnd)*(pow(xy,(dim+1)));
						deltaq =  pow(val,indi) - 1.0;
					}
					else
					{
						xy = 1.0-delta;
						val = 2.0*(1.0-rnd)+2.0*(rnd-0.5)*(pow(xy,(dim+1)));
						deltaq = 1.0 - (pow(val,indi));
					}

					/*Change the value for the parent */
					//  *ptr  = *ptr + deltaq*(yu-yl);
					// Added by Deb (31/10/01)
					y = y + deltaq * (yu-yl);
					if (y < yl) y=yl; 
					if (y > yu) y=yu;
					new_pop_ptr->ind[j].xreal[i] = y;
				}
				else // y == yl 
				{
					//xy = randomperc();

					if (!strcmp(mutation_mod,"random"))
						xy = randomperc();
					//else
					//	if (!strcmp(mutation_mod,"logistic"))
					//		fscanf(logistic_mut_ptr,"%f",&xy);
					//	else
					//		if (!strcmp(mutation_mod,"cat"))
					//			fscanf(cat_mut_ptr,"%f",&xy);
					if (!strcmp(mutation_mod,"logistic"))
					{
						key_lm = logistic_a * key_lm * (1 - key_lm);
						xy = key_lm;
					}
					if (!strcmp(mutation_mod,"cat"))			
					{
						temp_cm = catx_cm;
						catx_cm = catx_cm + caty_cm - floor(catx_cm + caty_cm);//递推公式
						caty_cm = temp_cm + 2 * caty_cm - floor(temp_cm + 2 * caty_cm);
						xy = catx_cm;
						//xy = caty_cm;
					}
					if (!strcmp(mutation_mod,"ICMIC"))
					{
						//if (ICMICm == 0)
						//	ICMICm = ICMICm + 0.00001;
						ICMICm = sinf(ICMIC_a/ICMICm);
						xy = (ICMICm+1)/2;
					}
					if (!strcmp(mutation_mod,"circle"))			
					{
						circlem = circlem + circle_b - (circle_a/2/pi)*sinf(2*pi*circlem)
							- floor(circlem + circle_b - (circle_a/2/pi)*sinf(2*pi*circlem));
						xy = circlem;
					}
					if (!strcmp(mutation_mod,"bakers"))			
					{
						if (bakers_xm>=0 && bakers_xm<0.5)
						{
							bakers_xm = 2 * bakers_xm;
							bakers_ym = bakers_ym / 2;
						}
						else
						{
							bakers_xm = 2 - 2 * bakers_xm;
							bakers_ym = 1 - bakers_ym / 2;
						}
						xy = bakers_xm;
					}
					if (!strcmp(mutation_mod,"zasla"))			
					{
						zasla_zm = cosf(2*pi*zasla_ym) + exp(-3)*zasla_zm;//递推公式
						zasla_ym = zasla_ym + 400 + 12.6695*zasla_zm
							- floor(zasla_ym + 400 + 12.6695*zasla_zm);
						//xy = zasla_ym;
						xy = (zasla_zm + 1.0513)/2.1026;
					}

					new_pop_ptr->ind[j].xreal[i] = xy*(yu - yl) + yl;
				}
				nmut++;
			}
			//  ptr++;
		}
	}  
	return ;
}