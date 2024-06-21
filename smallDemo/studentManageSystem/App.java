package smallDemo.studentManageSystem;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;


public class App {
    @SuppressWarnings("resource")
    public static void main(String[] args) {
        while (true) {
            ArrayList<User> list = new ArrayList<User>();
            System.out.println("欢迎来到学生信息管理系统");
            System.out.println("选择操作: 1登录 2注册 3忘记密码 4退出");
            Scanner sc = new Scanner(System.in);
            String choose = sc.next();
            switch (choose) {
                case "1" -> Login(list);
                case "2" -> Register(list);
                case "3" -> forgetPassword(list);
                case "4" -> {
                    System.out.println("谢谢使用");
                    System.exit(0);
                }
                default -> System.out.println("没有这个选项");
            }
        }
    }

    private static void forgetPassword(ArrayList<User> list) {
        Scanner sc = new Scanner(System.in);
        System.out.println("输入用户名");
        String username = sc.next();
        if (!contains(list, username)) {
            System.out.println("当前用户未注册");
            return ;
        }
        System.out.println("输入身份证号和手机号");
        String password = sc.next();
        String phoneNumber = sc.next();
        int index = findIndex(list, username);
        User user = list.get(index);
        if (!(password.equals(user.getPassword()) && password.equals(phoneNumber))) {
            System.out.println("输入有误");
            return ;
        }

        while (true) {
            System.out.println("输入注册密码");
            String newpassword = sc.next();
            System.out.println("再次输入注册密码");
            String againPassword = sc.next();

            if (!newpassword.equals(againPassword)) {
                System.out.println("两次密码输入不一致");
                continue;
            }
            user.setPassword(newpassword);
            break;
        }
    }

    private static int findIndex(ArrayList<User> list, String username) {
        for (int i = 0; i < list.size(); i++) {
            if (username.equals(list.get(i).getUsername())) {
                return i;
            }
        }
        return -1;
    }

    private static void Register(ArrayList<User> list) {
        User user = new User();
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("输入姓名");

            String username = sc.next();
            boolean isOk = checkUsername(username);
            if (!isOk) {
                System.out.println("用户名不满足条件,重新输入");
                continue;
            }

            boolean isOk2 = contains(list, username);
            if (isOk2) {
                System.out.println("用户名已存在");
            } else {
                user.setUsername(username);
                System.out.println("用户名可用");
                break;
            }
        }


        while (true) {
            System.out.println("输入注册密码");
            String password = sc.next();
            System.out.println("再次输入注册密码");
            String againPassword = sc.next();

            if (!password.equals(againPassword)) {
                System.out.println("两次密码输入不一致");
                continue;
            }
            user.setPassword(password);
            break;
        }

        while (true) {
            System.out.println("输入身份证号码");
            String personId = sc.next();
            boolean flag = checkPersonID(list, personId);

            if (flag) {
                user.setPersonID(personId);
                break;
            } else {
                System.out.println("输入有误,重新输入");
            }
        }

        while (true) {
            System.out.println("输入手机号");
            String phoneNum = sc.next();
            boolean flag = checkPhoneNum(list, phoneNum);

            if (flag) {
                user.setPhoneNum(phoneNum);
                break;
            } else {
                System.out.println("输入有误, 重新输入");
            }

        }
        System.out.println("输入成功");
        list.add(user);
    }

    private static boolean checkPhoneNum(ArrayList<User> list, String phoneNum) {
        if (phoneNum.length() != 11) return false;

        if (phoneNum.startsWith("0")) return false;

        int count = 0;

        for (int i = 0; i < phoneNum.length(); i++) {
            char c = phoneNum.charAt(i);
            if (c >= '0' && c <= '9') {
                count ++;
            }
        }

        return count == phoneNum.length();


    }

    private static boolean checkPersonID(ArrayList<User> list, String personId) {
        if (personId.length() != 18) return false;
        if (personId.charAt(0) == '0') return false;
        for (int i = 1; i < personId.length() - 1; i++) {
            char c = personId.charAt(i);
            if (c < '0' || c > '9') return false;
        }
        char c = personId.charAt(personId.length() - 1);
        return c >= '0' && c <= '9' || c == 'X' || c == 'x';

    }

    private static boolean contains(ArrayList<User> list, String username) {
        for (User user : list) {
            if (username.equals(user.getUsername())) {
                return true;
            }
        }
        return false;
    }

    private static boolean checkUsername(String username) {

        if (username.length() < 3 || username.length() > 16) {
            return false;
        }

        for (int i = 0; i < username.length(); i++) {
            char c = username.charAt(i);
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) continue;
            else {
                return false;
            }
        }

        int count = 0;
        for (int i = 0; i < username.length(); i++) {
            char c = username.charAt(i);
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
                count ++;
            }
        }
        return count > 0;
    }

    private static void Login(ArrayList<User> list) {
        Scanner sc = new Scanner(System.in);
        System.out.println("输入用户名");
        String username = sc.next();
        boolean flag = contains(list, username);
        if (!flag) {
            System.out.println("未注册");
            return ;
        }


        System.out.println("输入密码");
        String password = sc.next();
        String rightCode = getCode();

        while (true) {
            System.out.println("当前验证码为" + rightCode);
            System.out.println("请输入验证码");
            String code = sc.next();
            if (code.equalsIgnoreCase(rightCode)) {
                System.out.println("验证码正确");
                break;
            } else {
                System.out.println("验证码错误");
            }
        }
        User userInfo = new User(username, password, null, null);
        boolean result = checkUserInfo(list, userInfo);
        if (result) {
            System.out.println("登录成功");
            StudentSystem ss = new StudentSystem();
            ss.startStudentSystem();
        } else {
            System.out.println("登录失败");
        }



    }

    private static boolean checkUserInfo(ArrayList<User> list, User userInfo) {

        for (User user : list) {
            if (user.getUsername().equals(userInfo.getUsername()) && user.getPassword().equals(userInfo.getPassword())) {
                return true;
            }
        }

        return false;
    }

    // 生成一个 5位的验证码
    private static String getCode() {
        ArrayList<Character> list = new ArrayList<>();

        for (int i = 0; i < 26; i++) {
            list.add((char) ('a' + i));
            list.add((char) ('A' + i));
        }
        StringBuilder res = new StringBuilder();
        Random r = new Random();
        for (int i = 0; i < 4; i ++) {
            int index = r.nextInt(list.size());
            char c = list.get(index);
            res.append(c);
        }

        int num = r.nextInt(10);
        res.append(num);
        char[] arr = res.toString().toCharArray();
        int randomIndex = r.nextInt(arr.length);

        char tmp = arr[randomIndex];
        arr[randomIndex] = arr[arr.length - 1];
        arr[arr.length - 1] = tmp;
        return res.toString();
    }
}
