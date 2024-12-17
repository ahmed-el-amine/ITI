class ValidateArgs
{
	public static void main(String args[])
	{
		// validate if user enter two or more 
		switch (args.length)
		{
		  case 0:
		    System.out.println("Please Enter Two Args First Is String Sec Is How Many Times To Repeat That String");
		    return;
		  case 1:
		     System.out.println("You Enterd String => [" + args[0]  + "] Please Enter How Many Times To Print It");
		    return;
		}
			
		// add args in varable
		String stringArg = args[0];
		
		// check if user enter a valid number
		if (!UserValidation.isValidInt(args[1]))
		{
		  System.out.println("You Enterd Number Like This => [" + args[1]  + "] This Is Not Valid Number Please Enter A integer valid number format");
		  return;
		}
		// check if number large than 1
		int repeatTimes = Integer.parseInt(args[1]);
		if (repeatTimes <= 0)
		{
		  System.out.println("Please Enter Number Start From 1 You Have Enterd => [" + repeatTimes  + "]");
		  return;
		}
		
		for (int i = 0; i < repeatTimes; i++)
		{
		  System.out.println(stringArg);
		}
	}
}

class UserValidation
{
  public static boolean isValidInt(String x)
  {
    try {
      Integer.parseInt(x);
      return true;
    } catch (Exception e) {
      return false;
    }
  }
}
