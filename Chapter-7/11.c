#include <stdio.h>
#include <ctype.h>
#define ARTICHOKE 2.05		//��2.05��Ԫ/��
#define BEET 1.15			//���1.15��Ԫ/��
#define CARROT 1.09			//���ܲ�1.09��Ԫ/��
#define	DISCOUNT_LIMIT 100	
//��װ�Ѻ��˷Ѵ���Ҫ�󶩵�100��Ԫ
#define DISCOUNT_RATE 0.05	//�ۿ�Ϊ%5
#define BREAK1 5
#define BREAK2 20			//װ�˷ѵķֽ��
#define	FEE1 6.5
#define	FEE2 14
#define FEE3_RATE 0.5		
//��ͬ���������װ�˷ѣ����г���20����ÿ����һ��
//����0.5Ԫ
int main(void)
{
	double weight;
	double weight_artichoke = 0;
	double weight_beet = 0;
	double weight_carrot = 0;	//���������߲˵�����
	double total_weight;	//������
	double veg_cost;		//�����߲��ܹ�����
	double order_cost;		//�����ܶ�
	double total_cost;		//�����ܶ�
	double pack_tran_fee;	//װ�˷�
	double discount;
	int count = 0;
	char ch;

	printf("Please select the vegetables you want to buy:\n");
	printf("a: artichoke  $%.2f/lb\n", ARTICHOKE);
	printf("b: beet       $%.2f/lb\n", BEET);
	printf("c: carrot     $%.2f/lb\n", CARROT);
	printf("q: quit.\n");
	//��ӡѡ����Ϣ
	while ((ch = tolower(getchar())) != 'q')
	{
	//	if (ch == '\n')
	//		continue;					//�˵��س�
		switch (ch)
		{
			case 'a': printf("Input the weight of artichoke in pound: ");
					  scanf("%lf", &weight);
					  weight_artichoke += weight;
					  count++;
					  printf("Continue entering a, b, c or q: ");
					  break;
			case 'b': printf("Input the weight of beet in pound: ");
					  scanf("%lf", &weight);
					  weight_beet += weight;
					  count++;
					  printf("Continue entering a, b, c or q: ");
					  break;
			case 'c': printf("Input the weight of carrot in pound: ");
					  scanf("%lf", &weight);
					  weight_carrot += weight;
					  count++;
					  printf("Continue entering a, b, c or q: ");
					  break;
			default: printf("Please enter the right character.");
		}
		while (getchar () != '\n')
			continue;					//�˵�������������������ַ�
		
	}
	if (!count)
	{
		printf("Bye.\n");
		return 0;
	}										//��ʼ���q��ֱ���˳�
	total_weight = weight_artichoke + weight_beet + weight_carrot;
	veg_cost = weight_artichoke * ARTICHOKE + weight_beet * BEET
				+ weight_carrot * CARROT;
	discount = 0;
	if (veg_cost >= DISCOUNT_LIMIT)
	{
		discount = veg_cost * DISCOUNT_RATE;
		order_cost = veg_cost - discount;
	}                                
	else
		order_cost = veg_cost;				//�ۿۼ���
	
	if (total_weight <= BREAK1)
		pack_tran_fee = FEE1;
	else if (total_weight <= BREAK2)
		pack_tran_fee = FEE2;
	else
		pack_tran_fee = FEE2 + (total_weight - BREAK2) * FEE3_RATE;
	//װ�˷Ѽ���
	total_cost = order_cost + pack_tran_fee;
	
	printf("\nHere is what you choose:\n");
	if (weight_artichoke) {
		printf("artichoke   Price: $%.2f/lb  weight: %.2f pounds  cost: $%.2f\n", 
				ARTICHOKE, weight_artichoke, weight_artichoke * ARTICHOKE);
	}
	if (weight_beet) {
		printf("beet        Price: $%.2f/lb  weight: %.2f pounds  cost: $%.2f\n", 
				BEET, weight_beet, weight_beet * BEET);
	}
	if (weight_carrot) {
		printf("carrot      Price: $%.2f/lb  weight: %.2f pounds  cost: $%.2f\n", 
				CARROT, weight_carrot, weight_carrot * CARROT);
	}
	printf("The order cost: $%.2f\n", veg_cost);

	if (discount)
		printf ("You have %%%.f discount, and the reduced money is $%.2f\n",
				DISCOUNT_RATE * 100, discount);
	printf("The packing and transpoting fee is $%.2f\n", pack_tran_fee);
	printf("The total cost is $%.2f\n", total_cost);	
	//���������Ϣ

	return 0;
}
	





		
