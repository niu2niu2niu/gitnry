//��������Ԥ���ɺ���

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++����logistic����
void logistic_generation()
{
	float logistic_a=3.99,//�������
		key,//�����ֵ
		Logis;//��������ֵ

	int clm;

	FILE
		*li_ptr,//logistic��ʼ��Ⱥ
		*lc_ptr,//logistic��������
		*lcp_ptr,//logistic�������
		*lm_ptr,//logistic��������
		*lmp_ptr;//logistic�������

	/**************logistic�����ʼ��Ⱥ***************/
	if (!strcmp(init_mod,"logistic"))
	{
		li_ptr = fopen("logistic_init.out","w");

		key = randomperc();
		Logis = key;

		for (clm=0;clm<50;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//�Ȳ���50����֮��������Ը�ǿ
		}

		for (clm=0;clm<maxpop*maxvar;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//���ƹ�ʽ
			fprintf(li_ptr,"%f\n",Logis);
		}
		fclose(li_ptr);
	}

	/**************logistic���罻������***************/
	if (!strcmp(cross_mod,"logistic"))
	{
		lc_ptr = fopen("logistic_cross.out","w");

		key = randomperc();
		Logis = key;

		for (clm=0;clm<50;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//�Ȳ���50����֮��������Ը�ǿ
		}

		for (clm=0;clm<maxgen*maxpop*maxvar;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//���ƹ�ʽ
			fprintf(lc_ptr,"%f\n",Logis);
		}
		fclose(lc_ptr); 
	}
	/**************logistic���罻�����***************/
	if (!strcmp(cross_proba_mod,"logistic"))
	{
		lcp_ptr = fopen("logistic_cross_proba.out","w");

		key = randomperc();
		Logis = key;

		for (clm=0;clm<50;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//�Ȳ���50����֮��������Ը�ǿ
		}

		for (clm=0;clm<maxgen*maxpop;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//���ƹ�ʽ
			fprintf(lcp_ptr,"%f\n",Logis);
		}
		fclose(lcp_ptr);
	}

	/**************logistic�����������***************/
	if (!strcmp(mutation_mod,"logistic"))
	{
		lm_ptr = fopen("logistic_mut.out","w");

		key = randomperc();
		Logis = key;

		for (clm=0;clm<50;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//�Ȳ���50����֮��������Ը�ǿ
		}

		for (clm=0;clm<maxgen*maxpop*maxvar/2;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//���ƹ�ʽ
			fprintf(lm_ptr,"%f\n",Logis);
		}
		fclose(lm_ptr);
	}

	/**************logistic����������***************/
	if (!strcmp(mutation_proba_mod,"logistic"))
	{
		lmp_ptr = fopen("logistic_mut_proba.out","w");

		key = randomperc();
		Logis = key;

		for (clm=0;clm<50;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//�Ȳ���50����֮��������Ը�ǿ
		}

		for (clm=0;clm<maxgen*maxpop*maxvar/2;clm++)
		{
			Logis = logistic_a*Logis*(1-Logis);//���ƹ�ʽ
			fprintf(lmp_ptr,"%f\n",Logis);
		}
		fclose(lmp_ptr);
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++����cat����
void cat_generation()
{
	float catx,
		caty,
		temp;

	int ccm;

	FILE
		*ci_ptr,//cat��ʼ��Ⱥ
		*cc_ptr,//cat��������
		*ccp_ptr,//cat�������
		*cm_ptr,//cat��������
		*cmp_ptr;//cat�������

	/**************cat�����ʼ��Ⱥ***************/
	if (!strcmp(init_mod,"cat"))
	{
		ci_ptr = fopen("cat_init.out","w");

		catx = randomperc();
		caty = randomperc();
		fprintf(ci_ptr,"%f\n",catx);

		for (ccm=0;ccm<maxpop*maxvar;ccm++)
		{
			temp = catx;
			catx = catx + caty - floor(catx + caty);//���ƹ�ʽ
			caty = temp + 2 * caty - floor(temp + 2 * caty);
			fprintf(ci_ptr,"%f\n",catx);
		}

		fclose(ci_ptr);
	}

	/**************cat���罻������***************/
	if (!strcmp(cross_mod,"cat"))
	{
		cc_ptr = fopen("cat_cross.out","w");

		catx = randomperc();
		caty = randomperc();
		fprintf(cc_ptr,"%f\n",catx);

		for (ccm=0;ccm<maxgen*maxpop*maxvar;ccm++)
		{
			temp = catx;
			catx = catx + caty - floor(catx + caty);//���ƹ�ʽ
			caty = temp + 2 * caty - floor(temp + 2 * caty);
			fprintf(cc_ptr,"%f\n",catx);
		}

		fclose(cc_ptr); 
	}

	/**************cat���罻�����***************/
	if (!strcmp(cross_proba_mod,"cat"))
	{
		ccp_ptr = fopen("cat_cross_proba.out","w");

		catx = randomperc();
		caty = randomperc();
		fprintf(ccp_ptr,"%f\n",catx);

		for (ccm=0;ccm<maxgen*maxpop;ccm++)
		{
			temp = catx;
			catx = catx + caty - floor(catx + caty);//���ƹ�ʽ
			caty = temp + 2 * caty - floor(temp + 2 * caty);
			fprintf(ccp_ptr,"%f\n",catx);
		}

		fclose(ccp_ptr);
	}

	/**************cat�����������***************/
	if (!strcmp(mutation_mod,"cat"))
	{
		cm_ptr = fopen("cat_mut.out","w");

		catx = randomperc();
		caty = randomperc();
		fprintf(cm_ptr,"%f\n",catx);

		for (ccm=0;ccm<maxgen*maxpop*maxvar/2;ccm++)
		{
			temp = catx;
			catx = catx + caty - floor(catx + caty);//���ƹ�ʽ
			caty = temp + 2 * caty - floor(temp + 2 * caty);
			fprintf(cm_ptr,"%f\n",catx);
		}

		fclose(cm_ptr);
	}

	/**************cat����������***************/
	if (!strcmp(mutation_proba_mod,"cat"))
	{
		cmp_ptr = fopen("cat_mut_proba.out","w");

		catx = randomperc();
		caty = randomperc();
		fprintf(cmp_ptr,"%f\n",catx);

		for (ccm=0;ccm<maxgen*maxpop*maxvar/2;ccm++)
		{
			temp = catx;
			catx = catx + caty - floor(catx + caty);//���ƹ�ʽ
			caty = temp + 2 * caty - floor(temp + 2 * caty);
			fprintf(cmp_ptr,"%f\n",catx);
		}

		fclose(cmp_ptr);
	}
}