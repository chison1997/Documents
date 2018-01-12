package Samsung.java.hw2.Subject;

import java.io.IOException;
import java.util.Scanner;

public class SubjectManagement {
	
	static Subject s[] = new Subject[50];
	static int num = 0;
	static Scanner input = new Scanner(System.in);
	
	public static int find(String id)
	{
		for(int i = 0; i < num; i++)
		{
			if (s[i].getSubjectID().equals(id))
				return i;
		}
		return -1;
	}
	
	public static void append()
	{
		System.out.println();
		
		String name, id;
		int quota;
		System.out.print("Subject name: "); name = input.nextLine();
		
		do
		{
			System.out.print("Subject id: "); id = input.nextLine();
		}while(find(id) != -1);
		
		System.out.print("Quota: "); quota = input.nextInt();
		
		s[num] = new Subject(id, name, quota, 0);
		num ++;
		System.out.println("Successfully");
		
	}
	
	public static void update()
	{
		System.out.println();
		
		if (num == 0)
		{
			System.out.println("There isn't any subject");
			return;
		}
		String id;
		int index;
		
		do
		{
			System.out.print("Subject id: "); id = input.nextLine();
			index = find(id);
		}while(index == -1);
		
		s[index].displaySubjectInfo();
		
		System.out.println("-----------------");
		
		System.out.print("New subject name: "); s[index].setSubjectName(input.nextLine());
		
		do
		{
			System.out.print("New subject id: "); id = input.nextLine();
		}while(find(id) != -1);
		s[index].setSubjectID(id);
		
		System.out.print("New quota: "); s[index].setQuota(input.nextInt());
		
		System.out.print("New current enrolment : "); s[index].setCurrentEnrolment(input.nextInt());
		
		System.out.println("Successfully");
	}
	
	public static void display()
	{
		System.out.println();
		
		String id;
		int index;
		
		System.out.print("Subject id: "); id = input.nextLine();
		index = find(id);
		
		if (index == -1)
		{
			System.out.println("Subject not found");
		}
		else
		{
			s[index].displaySubjectInfo();
		}
	}
	
	public static void enrol()
	{
		System.out.println();
		
		String id;
		int index;
		
		System.out.print("Subject id: "); id = input.nextLine();
		index = find(id);
		
		if (index == -1)
		{
			System.out.println("Subject not found");
		}
		else
		{
			if (s[index].getCurrentEnrolment() < s[index].getQuota())
			{
				s[index].setCurrentEnrolment(s[index].getQuota());
				System.out.println("Successfully");
			}
			else
			{
				System.out.println("Can't enrol student");
			}
			
		}
	}
	
	public static void unenrol()
	{
		System.out.println();
		
		String id;
		int index;
		
		System.out.print("Subject id: "); id = input.nextLine();
		index = find(id);
		
		if (index == -1)
		{
			System.out.println("Subject not found");
		}
		else
		{
			if (s[index].getCurrentEnrolment() > 0)
			{
				s[index].setCurrentEnrolment(s[index].getQuota() - 1);
				System.out.println("Successfully");
			}
			else
			{
				System.out.println("Can't un-enrol student");
			}
			
		}
	}
	
	
	
	public static void main(String[] args) {
		char choice;
		
		do {
			System.out.println("Subject Management System");
			System.out.println("---------------------------------");
			System.out.println("1. Append new subject");
			System.out.println("2. Update subject");
			System.out.println("3. Display the information of subject");
			System.out.println("4. Enrol new student");
			System.out.println("5. Unenrol student");
			System.out.print("Your choice (1-5, other to quit): "); choice = input.nextLine().charAt(0);
			
			switch(choice)
			{
			case '1':
				System.out.println();
				append();
				break;
				
			case '2':
				update();
				break;
				
			case '3':
				display();
				break;
				
			case '4':
				enrol();
				break;
				
			case '5':
				unenrol();
				break;
			default:
				System.exit(0);
				
					
			}
			
			System.out.println("\nPress Enter to continue...");
	//		try
	//		{
	//			System.in.read();
	//		}
	//		catch (IOException e)
	//		{
	//			e.printStackTrace();
	//		}
			input.nextLine();
		
			System.out.println("\n---------------------------------\n");
		}while(true);
	}

}
