// Визначити чи є задане число досконалим (дорівнює сумі своїх дільників)
int main() {
	int ch=9, ch1=ch;
	for( int i=ch-1; i>0; i-- ){
		if( ch%i == 0){
			ch1-=i;
			if (ch1<=0){
				if (i==1){
					//число досконале
					break;
				} else {
					break;
					//число недосконале
				}
			}
		}
	}
	/* int i=ch-1;
	while (i>1){
		if( ch%i == 0){
			ch1-=i;
			if (ch1<=0){
				if (i==1){
					//число досконале
					break;
				} else {
					break;
					//число недосконале
				}
			}
		}
		i--;
		}
	*/
	/*
	int i = ch-1;
	do{
	if( ch%i == 0){
			ch1-=i;
			if (ch1<=0){
				if (i==1){
					//число досконале
					break;
				} else {
					break;
					//число недосконале
				}
			}
		}
		i--;
		}
		while(i>1);
		*/
	return 0;
}
