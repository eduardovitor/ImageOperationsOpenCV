#include <stdio.h> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;


void mostrarMenu(){
	printf("1- Soma e subtração \n2- Soma e subtração em escala de cinza \n3- HSV da imagem \n0- Sair \n");
}
int main() {
	int op;
	Mat imagem1=imread("imagem1.png");
	Mat imagem2=imread("imagem2.png");
	while(1){
		mostrarMenu();
		scanf("%d", &op);
		if(op==0){
			break;
		}
		else if(op==1){
			Mat resultado_soma=imagem1+imagem2;
			Mat resultado_subt=imagem1-imagem2;
			imshow("Soma", resultado_soma);
			imshow("Subtração", resultado_subt);
			waitKey(0);
		}
		else if(op==2){
			Mat imagem1_cinza;
			Mat imagem2_cinza;
			cvtColor(imagem1, imagem1_cinza, COLOR_BGR2GRAY);
			cvtColor(imagem2, imagem2_cinza, COLOR_BGR2GRAY);
			Mat resultado_soma=imagem1_cinza+imagem2_cinza;
			Mat resultado_subt=imagem1_cinza-imagem2_cinza;
			imshow("Soma", resultado_soma);
			imshow("Subtração", resultado_subt);
			waitKey(0);
		}
		else if(op==3){
			Mat imagem1_hsv;
			cvtColor(imagem1, imagem1_hsv,COLOR_BGR2HSV);
			imshow("Imagem HSV", imagem1_hsv);
			waitKey(0);
		}
   }
}
