import java.util.Date;

public class SelectionSort {
    public static void main(String[] args) {
        int cap = 5000;
        int teste = 1;
        float somaSelect = 0;
        float media;
        VetorDinamico v;
        long ini, fim;
        v = new VetorDinamico(cap);

        while (teste <= 20) {
          v.geraElementos();
          ini = new Date().getTime();
          v.selectionSort();
          fim = new Date().getTime();
          System.out.println(teste + "o selection de "+ cap +" demorou " + (fim-ini) + "ms");
          v.resetVetor();
          somaSelect += (fim-ini);
          teste++;
          
      }
      System.out.println("---------------------------------");
      System.out.printf("%f", somaSelect);
      System.out.printf("\n");
      media = somaSelect/20;
      System.out.printf("\nTamanho: %d\nTestes: 20\nMédia de ms selectionsort: %fms\n", cap, media);
      System.out.println("\n---------------------------------------------");
    }
    
}
