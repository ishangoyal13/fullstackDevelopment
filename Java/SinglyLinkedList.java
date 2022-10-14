import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String ch = "";
        LinkedList list = new LinkedList();
        do {
            System.out.println("Enter  the value");
            int n = sc.nextInt();
            sc.nextLine();
            list.addNode(n);
            System.out.println("Do you want to add another  node?  Type Yes/No");
            ch = sc.nextLine();
        } while (ch.equals("Yes"));
        System.out.println("Enter the element to be deleted");
        int d = sc.nextInt();
        list.delete(d);
        System.out.print("The elements in the linked list are  ");
        list.display();
        System.out.println();
        System.out.println("Total number of elements present in list are " + list.count());
    }

    static class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    static class LinkedList {
        Node head, next, temp, pre;

        public LinkedList() {
            head = null;
        }

        public void addNode(int data) {
            Node newnode = new Node(data);
            if (head == null) {
                head = newnode;
            } else {
                temp = head;
                while (temp.next != null) {
                    temp = temp.next;
                }
                temp.next = newnode;
            }
        }

        public int count() {
            temp = head;
            int count = 0;
            while (temp != null) {
                count++;
                temp = temp.next;
            }
            return count;
        }

        public void delete(int element) {
            temp = head;
            int k = 0;
            if (head.data == element) {
                head = head.next;
            }
            while (temp.next != null) {
                if (temp.next.data == element) {
                    k = 1;
                    temp.next = temp.next.next;
                } else {
                    pre = temp.next;
                    temp = temp.next;
                }
            }
            if (k == 1)
                System.out.println(element + " is deleted from the list");
            else
                System.out.println(element + " is not present in the list");
        }

        public void display() {
            temp = head;
            while (temp != null) {
                System.out.print(temp.data + " ");
                temp = temp.next;
            }
        }
    }
}