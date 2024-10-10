import java.util.Date;

public class InsertionSort {
    public static void main(String[] args) {
         //definindo o tamanho
        int cap = 5000;
        int teste = 1;
        float somaInsert = 0;
        float media;
        VetorDinamico v;
        long ini, fim;
        v = new VetorDinamico(cap);

        while (teste <= 20) {
          v.geraElementos();
          ini = new Date().getTime();
          v.insertionSort();
          fim = new Date().getTime();
          System.out.println(teste + "o insertion de "+ cap +" demorou " + (fim-ini) + "ms");
          v.resetVetor();
          somaInsert += (fim-ini); 
          teste++;
        }
        System.out.println("-----------------------------------");
        System.out.printf("%f ", somaInsert);
        System.out.print("\n");

        media = somaInsert/20;
        System.out.printf("\nTamanho: %d\nTestes: 20\nMédia de ms insertionsort: %fms\n", cap, media);    
        System.out.println("\n---------------------------------------------");
    }
}
