# IO

标签（空格分隔）： javaSE复习

---
## File类

File是java.io包下代表与平台无关的文件和目录，也就是说，如果希望在程序中操作文件和目录，都可以通过File类来完成。不管是文件还是目录都是使用File来操作的，File能新建、删除、重命名文件和目录，File不能访问文件本身。如果需要访问文件本身，需要使用输入输出流。

文件过滤器
File类的list()方法里可以接收一个FilenameFilter参数，通过该参数可以列出只符合条件的文件。FilenameFilter是函数式接口，包含一个accept(File dir,String name)方法。

下面列出当前路径下以.java结尾的文件以及文件夹。
```java
public class FileFilterTest {
    public static void main(String[] args) {
        File file = new File(".");
        String[] nameList=file.list((dir,name)->name.endsWith(".java")
                ||new File(name).isDirectory());
        for (String name : nameList) {
            System.out.println(name);
        }
    }
}
```
## 流

Java把所有设备里的有序数据抽象成流模型，简化了输入/输出处理，Java的IO流的40多个类都是从如下4个抽象积累派生出来的。

* InputStream/Reader:所有输入流的基类，前者字节输入流，后者字符输入流。
* OutputStream/Writer:所有输出流的基类，前者是字节输入流，后者是字符输出流。

按流的角色分，可以分为节点流和处理流。
可以从一个特定的IO设备（如磁盘、网络）读/写数据的流，称为节点流，也被称为低级流（low level stream）。
处理流则用于对一个已存在的流连接或封装，通过封装后的流来实现数据读/写功能，处理流也被称为高级流。

### 处理流的用法

处理流可以隐藏底层设备上节点流的差异，并对外提供方便的输入/输出方法，让程序员只需关心高级流的操作。
使用处理流的典型思路是，使用处理流来包装节点流，程序通过处理流来执行输入/输出功能。
识别处理流的方式很简单，只要流的构造器参数不是一个物理节点，而是一个已经存在的流，那么这种流一定是处理流；而所有的节点流都是直接以物理IO节点作为构造器参数的。

```java
public class PrintStreamTest {
    public static void main(String[] args) {
        try (
            FileOutputStream fos = new FileOutputStream("test.txt");
            PrintStream ps = new PrintStream(fos))
        {
            ps.println("hello world");
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```
在使用处理流包装了底层节点流之后，关闭输入/输出流资源时，只要关闭最上层的处理流即可。关闭最上层处理流时，系统会自动关闭被该处理流包装的节点流。

## 转换流
输入/输出流体系中还提供了两个转换流，这两个转换流用于将节点流转换成字符流，其中InputStreamReader将字节流转换成字符输入流，OutputStreamWriter将字节输入流转换成字符输出流。

下面以获取键盘输入为例来介绍转换流。Java使用System.in代表标准输入，即键盘输入，但这个输入流是InputStream类的实例，使用不太方便，而且键盘输入内容都是文本内容，所以可以使用InputStreamReader将其转换成字符输入流，还可以将这个字符输入流再次包装成BufferedReader，利用BufferedReader的readLine()方法可以一次读取一行。

```java
public class KeyinTest {
    public static void main(String[] args) {
        try (InputStreamReader reader = new InputStreamReader(System.in);
            BufferedReader br=new BufferedReader(reader);)
        {
          String line=null;
            while ((line = br.readLine()) != null) {
                if (line.equals("exit")) {
                    System.exit(1);
                }
                System.out.println("输入的内容是："+line);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
```

## 重定向标准输入/输出

Java的标准输入/输出分别通过System.in和System.out来代表，在默认情况下它们分别代表键盘和显示器，当程序通过System.in来获取输入时，实际是从键盘读取输入；当程序试图通过System.out执行输出时，程序总是输出到屏幕上。
在System类里有如下三个重定向标准输入/输出的方法。

* public static void setIn(InputStream in)
* public static void setOut(PrintStream out)
* public static void setErr(PrintStream err)

下面程序通过重定向标准输入流，将System.out的输出重定向到文件输出，而不是屏幕输出。
```java
public class RedirectOut {
    public static void main(String[] args) {
        try (PrintStream ps = new PrintStream("out.txt"))
        {
            System.setOut(ps);
            System.out.println("hello world!");

        } catch (IOException ioe) {
            ioe.printStackTrace();
        }

    }
}
```

```java
public class RedirectIn {
    public static void main(String[] args) {

        try (FileInputStream fis = new FileInputStream("F:\\IDEA_workspace\\javaSE\\src\\main\\java\\top\\sqmax\\chapter15\\RedirectOut.java"))
        {
            System.setIn(fis);
            Scanner sc=new Scanner(System.in);
            sc.useDelimiter("\n");
            while (sc.hasNext()) {
                System.out.println("键盘输入的内容是："+sc.next());
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
```

## RandomAccessFile

RandomAccessFile是Java输入/输出流体系中功能最丰富的文件访问类，它提供了众多的方法来访问文件内容，它既可以读取文件内容，也可以向文件输出数据。而且RandomAccessFile允许只有定位文件定位指针，可以将指针定位到文件的任意位置，进行读写。RandomAccessFile包含如下两个方法来操作文件记录指针。

* public void seek(long pos)
* public native long getFilePointer()

下面程序向指定文件追加内容。

```java
public class AppendContent {
    public static void main(String[] args) {
        try (RandomAccessFile raf = new RandomAccessFile("out.txt", "rw")) {
            raf.seek(raf.length());
            raf.write("追加的内容！\r\n".getBytes());
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
```

RandomAccessFile依然不能想文件指定位置插入内容，如果直接将文件记录指针移动到中间位置后开始输出，则新输出的内容会覆盖文件中原有的内容。我们可以把插入点后面的内容读入缓存区，等把需要插入的数据写入文件后，再将缓存区的内容追加到文件后面。

```java
public class InsertContent {
    public static void insert(String fileName,long pos,String insertContent) {
        File tmp= null;
        try {
            tmp = File.createTempFile("tmp",null);
        } catch (IOException e) {
            e.printStackTrace();
        }
        tmp.deleteOnExit();
        try (
            RandomAccessFile raf = new RandomAccessFile(fileName, "rw");
            RandomAccessFile tempContent = new RandomAccessFile(tmp, "rw")) {
            raf.seek(pos);
            byte[] bbuf = new byte[64];
            int hasRead = 0;
            while ((hasRead = raf.read(bbuf)) > 0) {
                tempContent.write(bbuf, 0, hasRead);
            }
            raf.seek(pos);
            raf.write(insertContent.getBytes());
            while ((hasRead = tempContent.read(bbuf)) > 0) {
                raf.write(bbuf, 0, hasRead);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws Exception{
        insert("InsertContent.java",45,"hello world\r\n");
    }
}
```

