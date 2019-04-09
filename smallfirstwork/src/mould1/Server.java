package mould1;

import mould1.Constant;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.locks.ReentrantLock;
import static mould1.Constant.write;

/**
 * �������
 */
public class Server {
    private static final String LOG = "In class : Server -->";

    private int port;
    private volatile int ticket;

    private Server(int ticket, int port) {
        this.ticket = ticket;
        this.port = port;
    }
    public synchronized boolean draw(int num)
    {
        if(ticket>=num) {
            ticket = ticket - num;
            return true;
        }
        else
            return false;
    }

    public static void main(String[] args) {
        new Server(20000, 8806).start();
    }

    private void start() {
        try{
            ServerSocket ss = new ServerSocket(port);
            while(true) {
                Socket s = ss.accept();
                new Thread(new ServerThread(s)).start();
            }
        }catch (IOException e) {
            e.printStackTrace();
        }
    }

    class ServerThread implements Runnable {
        Socket s = null;
        BufferedReader br = null;
        BufferedWriter ps = null;
        public ServerThread(Socket s) throws IOException {
            this.s = s;
            br = new BufferedReader(new InputStreamReader(s.getInputStream()));
            ps = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
        }
        public void run() {
               draw1();
               try{
                   Thread.sleep(10);
               }catch (Exception e) {
                   e.printStackTrace();
               }
        }
        public  void draw1(){
            try {
                String num = null;
                while ((num = br.readLine()) != null) {
                    if (draw(Integer.parseInt(num))) {
                        write(ps, num);
                        System.out.println(LOG + "ticket= " + ticket);
                    } else
                        break;

                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }
}
