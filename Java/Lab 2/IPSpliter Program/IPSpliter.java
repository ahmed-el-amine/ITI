import java.util.regex.Pattern;

class IPSplit
{
    public static void main(String args[])
    {
        String[] ips = { "256.1.1.1", "192.ad.1", "192.168", "192.168.01.1", "192.168.1.1" };

        for (String x: ips)
        {
            System.out.println(String.format("Using Regix This Ip [%s] is [%s]", x, IpValidator.isValidIP(x) ? "Valid 👌" : "Not Valid 🙅"));
            System.out.println(String.format("Using Custom Validation This Ip [%s] is [%s]", x, IpValidator.isValidIPCustom(x) ? "Valid 👌" : "Not Valid 🙅"));
            System.out.println("----------------");
        }
    }
}

class IpValidator {
    private static String IPv4_PATTERN =
    "^(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]|[0-9])\\." +
    "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]|[0-9])\\." +
    "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]|[0-9])\\." +
    "(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]|[0-9])$";
    
    private static Pattern ipv4Pattern = Pattern.compile(IPv4_PATTERN);

    private static boolean isValidInt(String x)
    {
        try {
            Integer.parseInt(x);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public static boolean isValidIP(String ipAddress)
    {
        if (ipAddress == null || ipAddress.isEmpty())  return false;

        if (!ipv4Pattern.matcher(ipAddress).matches()) return false;

        return true;
    }

    public static boolean isValidIPCustom(String ipAddress)
    {
        // first check if ip has 4 parts
        String[] ipParts = ipAddress.split("\\.");

        if (ipParts.length != 4) return false;

        // check if every part is int
        for (String x: ipParts)
        {
            // check if start with 0
            if (x.length() > 1 && x.startsWith("0")) return false;
            // check if x is valid int
            if (!isValidInt(x)) return false;
            // check if num is betwwen 0 and 255
            int num = Integer.parseInt(x);
            if (num < 0 || num > 255) return false;
        }

        return true;
    }
}