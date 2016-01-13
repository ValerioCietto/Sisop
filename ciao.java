
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication1;

/**
 *
 * @author valerio
 */
public class JavaApplication1 implements Runnable{

    /**
     * @param args the command line arguments
     */
  
    

        int counter = 0;
        

        public void run() {
            incr();
        }

        public void incr() {
            int temp;
            temp = counter;
            temp++;
            counter = temp;
            System.out.println(counter);
        }

        public static void main(String[] args) {
            JavaApplication1 es = new JavaApplication1();
            Thread t1 = new Thread(es);
            Thread t2 = new Thread(es);
            t1.start();
            t2.start();
            
        }
    }
    


