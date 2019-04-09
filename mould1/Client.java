package mould1;


import mould1.Constant;

import java.io.*;
import java.io.IOException;
import java.net.Socket;

import static java.lang.System.exit;
import static mould1.Constant.SUCCESS;
import static mould1.Constant.random;
import static mould1.Constant.write;

/**
 * �ͻ�����
 */
public class Client {

    private static final String LOG = "In class : Client -->";

    private String host;
    private int port;
    String num;

    private volatile int ticket;

    private Client(String host, int port) {
        this.host = host;
        this.port = port;
        ticket = 0;
    }

    public static void main(String[] args) {
        new Client("localhost", 8806).start();
    }

    private void start() {
        Socket s = null;
        try {
            s = new Socket("127.0.0.1", port);
            new Thread(new ClientThread(s), LOG).start();
            BufferedWriter ps = new BufferedWriter(new OutputStreamWriter((s.getOutputStream())));
            while(true){
                random(new mould1.Constant.Operation() {
                    public mould1.Constant sell() {
                        num = String.valueOf(1);
                        return SUCCESS;
                    }

                    public mould1.Constant refund() {
                        if(ticket > 1) {
                            num = String.valueOf(-1);
                        }return SUCCESS;
                    }
                });
                write(ps,num);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            System.out.println("对不起，程序错误，请重新启动 ");
        }
    }

    class ClientThread implements Runnable {
        private Socket s;
        BufferedReader br = null;
        String num1;

        public ClientThread(Socket s) throws IOException {
            this.s = s;
            br = new BufferedReader(new InputStreamReader((s.getInputStream())));
        }

        public void run() {
            try {
                while ((num1 = br.readLine()) != null) {
                    ticket = ticket + Integer.parseInt(num1);
                    System.out.println(Thread.currentThread().getName() + "ticket = " + ticket);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
