/*This is the file which initializes the population*/
void realinit(population *pop_ptr);

void realinit(population *pop_ptr)
{
	int i,j,r,d2;
	float d,d1;  

	for (i = 0 ; i < popsize ; i++)
	{ 
		for (j = 0; j < nvar; j++)
		{
			//d = randomperc();

			if (!strcmp(init_mod,"random"))
				d = randomperc();
			//else
			// if (!strcmp(init_mod,"logistic"))
			//  fscanf(logistic_init_ptr,"%f",&d);
			// else
			//  if (!strcmp(init_mod,"cat"))
			//	  fscanf(cat_init_ptr,"%f",&d);
			if (!strcmp(init_mod,"logistic"))			
			{
				key_li = logistic_a * key_li * (1 - key_li);
				d = key_li;
			}
			if (!strcmp(init_mod,"cat"))			
			{
				temp_ci = catx_ci;
				catx_ci = catx_ci + caty_ci - floor(catx_ci + caty_ci);//递推公式
				caty_ci = temp_ci + 2 * caty_ci - floor(temp_ci + 2 * caty_ci);
				d = catx_ci;
				//d = caty_ci;
			}
			if (!strcmp(init_mod,"ICMIC"))			
			{
				//if (ICMICi == 0)
				//	ICMICi = ICMICi + 0.00001;
				ICMICi = sinf(ICMIC_a/ICMICi);
				d = (ICMICi+1)/2;
			}
			if (!strcmp(init_mod,"circle"))			
			{
				circlei = circlei + circle_b - (circle_a/2/pi)*sinf(2*pi*circlei)
					- floor(circlei + circle_b - (circle_a/2/pi)*sinf(2*pi*circlei));
				d = circlei;
			}
			if (!strcmp(init_mod,"bakers"))			
			{
				if (bakers_xi>=0 && bakers_xi<0.5)
				{
					bakers_xi = 2 * bakers_xi;
					bakers_yi = bakers_yi / 2;
				}
				else
				{
					bakers_xi = 2 - 2 * bakers_xi;
					bakers_yi = 1 - bakers_yi / 2;
				}
				d = bakers_xi;
			}
			//if (!strcmp(init_mod,"tinker"))			
			//{
			//	if (tinker_xi>=-1.4 && tinker_xi<=0.5 && tinker_yi>=-1.6 && tinker_yi<=0.6)
			//	{
			//	temp_tinker_xi = tinker_xi;
			//	tinker_xi = tinker_xi*tinker_xi - tinker_yi*tinker_yi
			//		+ tinker_a*tinker_xi + tinker_b*tinker_yi;//递推公式
			//	tinker_yi = 2*temp_tinker_xi*tinker_yi + tinker_c*temp_tinker_xi
			//		+ tinker_d*tinker_yi;				
			//	d = (tinker_xi + 1.4)/1.9;
			//	}
			//	else
			//	{
			//		printf("ERRRORRR \n");
			//	}
			//}
			if (!strcmp(init_mod,"zasla"))			
			{
				zasla_zi = cosf(2*pi*zasla_yi) + exp(-3)*zasla_zi;//递推公式
				zasla_yi = zasla_yi + 400 + 12.6695*zasla_zi
					- floor(zasla_yi + 400 + 12.6695*zasla_zi);
				//d = zasla_yi;
				d = (zasla_zi + 1.0513)/2.1026;
			}

			d1 = 2*d - 1;
			/*if limits are not specified then generates any number between 
			zero and infinity*/
			if(ans != 1)
			{
				pop_ptr->ind[i].xreal[j] = 1/d1 ;
			}

			/*if limits are specified it generates the value in 
			range of minimum and maximum value of the variable*/
			else
			{
				pop_ptr->ind[i].xreal[j] = d*(lim_r[j][1] - lim_r[j][0])+lim_r[j][0];
			}
		}
		/* pop_ptr->ind_ptr = &(pop_ptr->ind[i+1]); */
	}
	/*pop_ptr->ind_ptr = &(pop_ptr->ind[0]); */
	return; 
}