
package smallDemo.studentManageSystem;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * StudentSystem
 */
public class StudentSystem {

    public static void startStudentSystem() {
        ArrayList<Student> students = new ArrayList<>();

        while (true) {
            System.out.println("-----------------欢迎来到学生管理系统----------------------------");
            System.out.println("1.添加学生");
            System.out.println("2.删除学生");
            System.out.println("3.修改学生");
            System.out.println("4.查询学生");
            System.out.println("5.退出");
            System.out.println("请输入你的选择:");


            Scanner sc = new Scanner(System.in);
            String choose = sc.next();
            switch (choose) {
                case "1" -> addStudent(students);
                case "2" -> delStudent(students);
                case "3" -> updateStudent(students);
                case "4" -> queryStudent(students);
                case "5" -> {
                    System.out.println("退出");
                    System.exit(0);
                }
                default -> System.out.println("没有这个选项");
            }
        }
        
    }

    private static void queryStudent(ArrayList<Student> list) {
        // TODO Auto-generated method stub
        if (list.size() == 0) {
            System.out.println("当前无学生信息,请添加后查询");
            return ;
        }
        System.out.println("id\t\t姓名\t年龄\t家庭住址");
        for (int i = 0; i < list.size(); i ++) {
            Student stu = list.get(i);
            System.out.println(stu.getId() + "\t" + stu.getName() + '\t' + stu.getAge() + '\t' + stu.getAddress());
        }
    }

    private static void updateStudent(ArrayList<Student> list) {
        Scanner sc = new Scanner(System.in);
        System.out.println("输入要修改的 id:");
        String id = sc.next();
        int index = getIndex(list, id);
        if (index >= 0) {
            Student stu = list.get(index);
            System.out.println("输入要修改的学生姓名, 年龄, 家庭住址");
            String name = sc.next();
            int age = sc.nextInt();
            String address = sc.next();
            stu.setName(name);
            stu.setAge(age);
            stu.setAddress(address);
            System.out.println("修改成功");
        } else {
            System.out.println("没有该 id");
        }
    }

    private static void delStudent(ArrayList<Student> list) {

        Scanner sc = new Scanner(System.in);
        System.out.println("输入要删除的 ID");
        String id = sc.next();

        int index = getIndex(list, id);

        if (index >= 0) {
            list.remove(index);
            System.out.println("ID 为:" + id + "的学生已删除");
        } else {
            System.out.println("ID不存在,删除失败");
        }

    }

    private static void addStudent(ArrayList<Student> list) {

        Scanner sc = new Scanner(System.in);
        String id = null;
        while (true) {
            System.out.println("输入 id:");
            id = sc.next();
            boolean flag = contains(list, id);
            if (flag) {
                System.out.println("id 已经存在");
            } else break;
        }

        System.out.println("输入姓名:");
        String name = sc.next();
        System.out.println("输入年龄:");
        int age = sc.nextInt();
        System.out.println("输入住址:");
        String address = sc.next();
        Student stu = new Student(name, id, age, address);
        list.add(stu);
        System.out.println("添加成功");
    }

    
    private static boolean contains(ArrayList<Student> list, String id) {
        return getIndex(list, id) >= 0;
    }

    public static int getIndex(ArrayList<Student> list, String id) {
        for (int i = 0; i < list.size(); i ++) {
            Student stu = list.get(i);
            String sid = stu.getId();
            if (sid.equals(id)) return i;
        }
        return -1;
    }
}