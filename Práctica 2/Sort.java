// fichero Sort.java

import java.util.Date;

public class Sort {
	public static void main(String[] args)
	{
        boolean imprimir=true;
        int n = 5000;
        // generar n números aleatoriamente
        int [] v1 = new int[n];
        for (int i=0; i<n; i++) {
            v1[i] = (int) (Math.random()*100);
        }
        // hacer copias de v1[]
        int [] v2 = (int[])v1.clone();
        int [] v3 = (int[])v1.clone();
        int [] v4 = (int[])v1.clone();
        int [] v5 = (int[])v1.clone();
		         
        if (imprimir==true && n<=100) {
            System.out.println("Vector antes de ordenar:");
            for (int i=0; i<n; i++) 
                System.out.println("v1["+i+"] = "+v1[i]);
        }
        
        // ordenar los números mediante burbuja1()
        Date antes = new Date();
        Burbuja.burbuja1(v1, n);
        Date despues = new Date();
        long etime = despues.getTime()-antes.getTime();
        System.out.println("\nTiempo utilizado por burbuja1(): " +
                           etime + " milisegundos.");
        
        // ordenar los números mediante burbuja2()
        antes = new Date();
        Burbuja.burbuja2(v2, n);
        despues = new Date();
        etime = despues.getTime()-antes.getTime();
        System.out.println("\nTiempo utilizado por burbuja2(): " +
                           etime + " milisegundos.");
        
        // ordenar los números mediante burbujaDoble()
        antes = new Date();
        Burbuja.burbujaDoble(v3, n);
        despues = new Date();
        etime = despues.getTime()-antes.getTime();
        System.out.println("\nTiempo utilizado por burbujaDoble(): " +
                           etime + " milisegundos.");
		
        // ordenar los números mediante mergesort()
        antes = new Date();
        Mergesort.mergesort(v4, n);
        despues = new Date();
        etime = despues.getTime()-antes.getTime();
        System.out.println("\nTiempo utilizado por mergesort(): " +
                           etime + " milisegundos.");
		
        // ordenar los números mediante quicksort()
        antes = new Date();
        Quicksort.quicksort(v5, 0, v5.length-1);
        despues = new Date();
        etime = despues.getTime()-antes.getTime();
        System.out.println("\nTiempo utilizado por quicksort(): " +
                           etime + " milisegundos.");
     
        if (imprimir==true && n<=100) {
            System.out.println("\nVector después de ordenar:");
            for (int i=0; i<n; i++) 
                System.out.println("v1["+i+"] = "+v1[i]);
        }
        System.out.println("Ya he terminado.");
        
	} // fin de main()
    
} // fin de clase Sort
