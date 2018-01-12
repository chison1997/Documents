package Samsung.java.hw2.Subject;

public class Subject {
	private String subjectID;
	private String subjectName;
	private int quota;
	private int currentEnrolment;
	
	
	
	
	public String getSubjectID() {
		return subjectID;
	}

	public void setSubjectID(String subjectID) {
		this.subjectID = subjectID;
	}

	public String getSubjectName() {
		return subjectName;
	}

	public void setSubjectName(String subjectName) {
		this.subjectName = subjectName;
	}

	public int getQuota() {
		return quota;
	}

	public void setQuota(int quota) {
		this.quota = quota;
	}

	public int getCurrentEnrolment() {
		return currentEnrolment;
	}

	public void setCurrentEnrolment(int currentEnrolment) {
		this.currentEnrolment = currentEnrolment;
	}

	public Subject()
	{
		this.quota = 0;
	}
	
	
	public Subject(String initID, String initName, int initQuota, int initCurrentEnrolment)
	{
		this.subjectID = initID;
		this.subjectName = initName;
		this.quota = initQuota;
		this.currentEnrolment = initCurrentEnrolment;
	}
	
	public void enrolStudent()
	{
		System.out.println("Enrolling student...");
		if (currentEnrolment < quota)
		{
			currentEnrolment ++;
			System.out.println("Student enrolled in " + subjectName);
		}
		else
		{
			System.out.println("Quota reached, enrolment failed");
		}
	}
	
	public void unEnrolStudent() {
		System.out.println("Un-enrolling student...");
		if (currentEnrolment <= 0)
			System.out.println("No students to un-enrol");
		else
		{
			currentEnrolment --;
			System.out.println("Student un-enrolled from " + subjectName);
		}
	}
	
	public  void displaySubjectInfo()
	{
		System.out.println("Subject ID: " + subjectID);
		System.out.println("Subject name: " + subjectName);
		System.out.println("Quota: " + quota);
		System.out.println("Currently enrolled: " + currentEnrolment);
		int availablePlaces = quota - currentEnrolment;
		System.out.println("Can accept " + availablePlaces + " more students");
	}
	
	
	
}
