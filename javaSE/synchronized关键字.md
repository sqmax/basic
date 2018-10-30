# synchronized关键字

标签（空格分隔）： javaSE复习 面试题

---

在多线程编程中synchronized一直是元老级的角色，很多人称呼它为重量级锁。Java6之后为了减少获得锁和释放锁带来的性能消耗引入了偏向锁和轻量级锁，对synchronized进行了各种优化，它变得不那么重了。

synchronized实现同步的基础是：Java中的每一个对象都可以作为锁。
具体见以下四种形式，其中1，2属于同一类，都是对一个普通的对象加锁，3，4属于同一类，都是对类的class对象加锁。

* 对于普通同步方法，锁是当前实例对象，即this。
* 对于同步方法块，锁是synchronized括号里配置的对象，这个对象也可以是this。
* 对于静态同步方法，锁是当前类的class对象。
* 对于另一种同步方法块（synchronized括号里是类的class对象），和第三种情况一样，锁是当前类的class对象。

当一个线程试图访问同步代码块时，它首先必须得到锁，推出或抛出异常是就会释放锁。

下面对第四种情况做一个演示：

```java
class ServiceObj{
    public void doService() {
        synchronized (ServiceObj.class) {
            System.out.println(Thread.currentThread().getName()+"的业务方法开始");
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(Thread.currentThread().getName()+"的业务方法结束");
        }
    }
}
class MyThread extends Thread{
    private ServiceObj serviceObj;

    public MyThread(ServiceObj serviceObj) {
        super();
        this.serviceObj=serviceObj;
    }

    @Override
    public void run() {
        serviceObj.doService();
    }
}
public class SynchTest {
    public static void main(String[] args) {
        ServiceObj serviceObj0 = new ServiceObj();
        MyThread myThread0 = new MyThread(serviceObj0);
        myThread0.start();

        ServiceObj serviceObj1=new ServiceObj();
        MyThread myThread1=new MyThread(serviceObj1);
        myThread1.start();

    }
}
```
输出结果如下：

```
Thread-0的业务方法开始
Thread-0的业务方法结束
Thread-1的业务方法开始
Thread-1的业务方法结束
```
可以看到两个线程保持同步。

但如果我们把synchronized括号里的内容改一下,变为情况二：

```
synchronized (this)
```
输出结果就不同步了，如下：

```
Thread-0的业务方法开始
Thread-1的业务方法开始
Thread-1的业务方法结束
Thread-0的业务方法结束
```





