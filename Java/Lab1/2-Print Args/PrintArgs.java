class PrintArgs
{
	public static void main(String args[])
	{
		if (args.length == 0)
		{
			System.out.println("Please Enter Minimum 1 Arg To Print it");
		}
		else
		{
			for (int i = 0; i < args.length; i++)
			{
				System.out.println(args[i]);
			}
		}
	}
}
