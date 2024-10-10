import java.util.Date;

public class BubbleSort {
    public static void main(String[] args) {
         //definindo o tamanho
        int cap = 5000;
        int teste = 1;
        float somaBubble = 0;
        float media;
        VetorDinamico v;
        long ini, fim;
        v = new VetorDinamico(cap);

        while (teste <= 20) {
            v.geraElementos();
            ini = new Date().getTime();
            v.bubbleSort();
            fim = new Date().getTime();
            System.out.println(teste + "o bubble de tamanho " + cap + " demorou " + (fim-ini) + "ms");
            v.resetVetor();
            somaBubble += (fim-ini);      
            teste++;
                 
        }
        System.out.println("----------------------------------------");
        System.out.printf("%.1f ", somaBubble);
        System.out.printf("\n");
        media = somaBubble/20;
        //mostrando a média
        System.out.printf("\nTamanho: %d\nTestes: 20\nMédia de ms bubblesort: %.1fms\n", cap, media);
        System.out.println("\n---------------------------------------------");
    }
}
