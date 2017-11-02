//混沌序列预生成函数

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++生成logistic序列
void logistic_generation()
{
	float logistic_a=3.99,//混沌参数
		key,//混沌初值
		Logis;//各步混沌值

	int clm;

	FILE
		*li_ptr,//logistic初始种群
		*lc_ptr,//logistic交叉算子
		*lcp_ptr,//logistic交叉概率
		*lm_ptr,//logistic变异算子
		*lmp_ptr;//logistic变异概率

	/**************logistic混沌初始种群***************/
	if (!strcmp(init_mod,"logistic"))
	{
		li_ptr = fopen("logistic_init.out","w");

		key = randomperc();
		Logis = key;

		for (clm=0;clm<50;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//先产生50个，之后混沌特性更强
		}

		for (clm=0;clm<maxpop*maxvar;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//递推公式
			fprintf(li_ptr,"%f\n",Logis);
		}
		fclose(li_ptr);
	}

	/**************logistic混沌交叉算子***************/
	if (!strcmp(cross_mod,"logistic"))
	{
		lc_ptr = fopen("logistic_cross.out","w");

		key = randomperc();
		Logis = key;

		for (clm=0;clm<50;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//先产生50个，之后混沌特性更强
		}

		for (clm=0;clm<maxgen*maxpop*maxvar;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//递推公式
			fprintf(lc_ptr,"%f\n",Logis);
		}
		fclose(lc_ptr); 
	}
	/**************logistic混沌交叉概率***************/
	if (!strcmp(cross_proba_mod,"logistic"))
	{
		lcp_ptr = fopen("logistic_cross_proba.out","w");

		key = randomperc();
		Logis = key;

		for (clm=0;clm<50;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//先产生50个，之后混沌特性更强
		}

		for (clm=0;clm<maxgen*maxpop;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//递推公式
			fprintf(lcp_ptr,"%f\n",Logis);
		}
		fclose(lcp_ptr);
	}

	/**************logistic混沌变异算子***************/
	if (!strcmp(mutation_mod,"logistic"))
	{
		lm_ptr = fopen("logistic_mut.out","w");

		key = randomperc();
		Logis = key;

		for (clm=0;clm<50;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//先产生50个，之后混沌特性更强
		}

		for (clm=0;clm<maxgen*maxpop*maxvar/2;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//递推公式
			fprintf(lm_ptr,"%f\n",Logis);
		}
		fclose(lm_ptr);
	}

	/**************logistic混沌变异概率***************/
	if (!strcmp(mutation_proba_mod,"logistic"))
	{
		lmp_ptr = fopen("logistic_mut_proba.out","w");

		key = randomperc();
		Logis = key;

		for (clm=0;clm<50;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//先产生50个，之后混沌特性更强
		}

		for (clm=0;clm<maxgen*maxpop*maxvar/2;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//递推公式
			fprintf(lmp_ptr,"%f\n",Logis);
		}
		fclose(lmp_ptr);
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++生成cat序列
void cat_generation()
{
	float catx,
		caty,
		temp;

	int ccm;

	FILE
		*ci_ptr,//cat初始种群
		*cc_ptr,//cat交叉算子
		*ccp_ptr,//cat交叉概率
		*cm_ptr,//cat变异算子
		*cmp_ptr;//cat变异概率

	/**************cat混沌初始种群***************/
	if (!strcmp(init_mod,"cat"))
	{
		ci_ptr = fopen("cat_init.out","w");

		catx = randomperc();
		caty = randomperc();
		fprintf(ci_ptr,"%f\n",catx);

		for (ccm=0;ccm<maxpop*maxvar;ccm++)
		{
			temp = catx;
			catx = catx + caty - floor(catx + caty);//递推公式
			caty = temp + 2 * caty - floor(temp + 2 * caty);
			fprintf(ci_ptr,"%f\n",catx);
		}

		fclose(ci_ptr);
	}

	/**************cat混沌交叉算子***************/
	if (!strcmp(cross_mod,"cat"))
	{
		cc_ptr = fopen("cat_cross.out","w");

		catx = randomperc();
		caty = randomperc();
		fprintf(cc_ptr,"%f\n",catx);

		for (ccm=0;ccm<maxgen*maxpop*maxvar;ccm++)
		{
			temp = catx;
			catx = catx + caty - floor(catx + caty);//递推公式
			caty = temp + 2 * caty - floor(temp + 2 * caty);
			fprintf(cc_ptr,"%f\n",catx);
		}

		fclose(cc_ptr); 
	}

	/**************cat混沌交叉概率***************/
	if (!strcmp(cross_proba_mod,"cat"))
	{
		ccp_ptr = fopen("cat_cross_proba.out","w");

		catx = randomperc();
		caty = randomperc();
		fprintf(ccp_ptr,"%f\n",catx);

		for (ccm=0;ccm<maxgen*maxpop;ccm++)
		{
			temp = catx;
			catx = catx + caty - floor(catx + caty);//递推公式
			caty = temp + 2 * caty - floor(temp + 2 * caty);
			fprintf(ccp_ptr,"%f\n",catx);
		}

		fclose(ccp_ptr);
	}

	/**************cat混沌变异算子***************/
	if (!strcmp(mutation_mod,"cat"))
	{
		cm_ptr = fopen("cat_mut.out","w");

		catx = randomperc();
		caty = randomperc();
		fprintf(cm_ptr,"%f\n",catx);

		for (ccm=0;ccm<maxgen*maxpop*maxvar/2;ccm++)
		{
			temp = catx;
			catx = catx + caty - floor(catx + caty);//递推公式
			caty = temp + 2 * caty - floor(temp + 2 * caty);
			fprintf(cm_ptr,"%f\n",catx);
		}

		fclose(cm_ptr);
	}

	/**************cat混沌变异概率***************/
	if (!strcmp(mutation_proba_mod,"cat"))
	{
		cmp_ptr = fopen("cat_mut_proba.out","w");

		catx = randomperc();
		caty = randomperc();
		fprintf(cmp_ptr,"%f\n",catx);

		for (ccm=0;ccm<maxgen*maxpop*maxvar/2;ccm++)
		{
			temp = catx;
			catx = catx + caty - floor(catx + caty);//递推公式
			caty = temp + 2 * caty - floor(temp + 2 * caty);
			fprintf(cmp_ptr,"%f\n",catx);
		}

		fclose(cmp_ptr);
	}
}