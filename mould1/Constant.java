
package mould1;

import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.IOException;
import java.util.Random;

/**
 * 状态：成功/失败
 */
public enum Constant {
    SUCCESS, FAIL;

    /**
     * 状态字符串：成功/失败
     */
    public static final String STR_SUCCESS = "success";
    public static final String STR_FAIL = "fail";

    /**
     * 指定行为：售票/退票
     */
    public static final String OPERATION_SELL = "sell";
    public static final String OPERATION_REFUND = "refund";

    public static Constant success() {
        return SUCCESS;
    }

    public static Constant fail() {
        return FAIL;
    }

    public interface Operation {
        Constant sell();

        Constant refund();
    }

    /**
     * 随机函数（回调形式）
     *
     * @param operation 随机调用sell和refund
     */
    public static void random(Operation operation) {
        if (new Random().nextInt(10000) % 3 != 0) {
            operation.sell();
        } else {
            operation.refund();
        }
    }

    /**
     * 随机函数
     *
     * @return 随机布尔值，购票几率大于退票
     */
    public static boolean random() {
        return new Random().nextInt(10000) % 3 != 0;
    }

    /**
     * 关闭流
     *
     * @param closer array of closeable
     * @throws IOException IOException
     */
    public static void close(Closeable... closer) throws IOException {
        for (Closeable c : closer) {
            if (c != null) {
                c.close();
            }
        }
    }

    /**
     * 写出，避免换行和缓存区产生的readLine问题
     *
     * @param writer BufferedWriter
     * @param msg    msg
     * @throws IOException IOException
     */
    public static void write(BufferedWriter writer, String msg) {
        try {
            writer.write(msg);
            writer.write("\n");
            writer.flush();
        }catch(IOException e) {
            e.printStackTrace();
        }
    }

}
