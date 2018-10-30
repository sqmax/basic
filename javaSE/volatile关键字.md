# volatile关键字

标签（空格分隔）： 多线程 面试题 javaSE复习

---

## volatile关键字


在java2以前，Java的内存模型总是从主存（共享内存）读取变量，而在当前的Java内存模型下，每个线程把变量保存到本地内存中，而不是直接在主存中进行读写。这就可能造成一个线程在主存中修改了一个变量的值，而另一个线程还在继续使用它在本地内存中的值。这个问题就是变量在多线程中的可见性问题。

要解决这个问题，就需要把变量生命为volatile，这就指示JVM,这个变量是不稳定的，每个线程访问该变量，它都到主内存中读取，而且，当变量变化时，强迫线程将变化值回写到主存。这样在任何时刻，两个不同的线程总是看到某个成员变量的同一个值，这样也保证了变量在多线程之间的可见性。

看下面一个例子：
```
public class VolatileTest extends Thread {

    private static boolean flag =true;
    @Override
    public void run() {
        System.out.println("进入run了");
        while (flag == true) {}
        System.out.println("线程被停止了！");
    }

    public static void main(String[] args) {
        VolatileTest volatileTest=new VolatileTest();
        volatileTest.start();
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        volatileTest.flag=false;
        System.out.println("已经将isRunning赋值为false");
    }
}
```
运行结果：
```
进入run了
已经将isRunning赋值为false
```
可以看到没有“输出线程被停止!”。线程进入了死循环。
这是因为main线程和volatileTest线程各自有一个工作线程，里面有变量flag的拷贝，flag在这两个线程之间不可见，即main线程修改了自己工作内存中flag的值，volatileTest线程并不知道。

现在我们把flag前面加上关键字volatile，如下：
```java
volatile private static  boolean flag =true;
```
输出就变成下面：
```
进入run了
已经将isRunning赋值为false
线程被停止了！
```
这是因为volatile保证了变量在不同线程之间的可见性。

如果我们不想给flag前家volatile关键字，也可以通过下面的方式解决：在whiel循环里任意家上一个输出语句或将该线程sleep一下。
```
volatile private static  boolean flag =true;
    @Override
    public void run() {
        System.out.println("进入run了");
        while (flag == true) {
            //法1：加一个循环语句
            System.out.println("hello world");
            //法2：将当前线程sleep一下
//            try {
//                Thread.sleep(1000);
//            } catch (InterruptedException e) {
//                e.printStackTrace();
//            }
        }
        System.out.println("线程被停止了！");
    }
```
为什么呢？
因为JVM会尽力保证变量的可见性，即便这个变量没有加volatile关键字只要CPU有时间，JVM就会尽力去保证变量值的更新。这与volatile关键字的不同之处在于，volatile会强制保证变量的可见性；而不加volatile关键字，JVM只会尽力去保证变量的可见性，如果CPU一直有其它的事情处理，它也就不会去保证了。最开始，CPU一直处于占用状态，JVM不会强制CPU其主存中取变量的最新值，所以死循环。后来加入输出语句或sleep线程，CPU就有时间去保证变量的可见性，即从主内存中去变量flag的值。

>问题：为什么加入输出语句，CPU就有时间了？


## synchronized和volatile的比较

* volatile是保证数据在多线程之间的可见性的，而synchronized是解决资源在多线程之间的同步，同一时间，只有一个线程会获取资源。
* 多线程访问volatile关键字不会发生阻塞，而synchronized会发生阻塞。
* volatile只能修饰变量，synchronized可以修饰方法，代码块。
* synchronized在Java6之后引入了偏向锁和轻量级锁，减少获得锁和释放锁带来的性能消耗。















