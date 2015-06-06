package person;

import org.junit.Assert;
import org.junit.Test;

/**
 * Created by inad on 14/04/15.
 */
public class Person {
    String lastName = "";
    String firstName = "";

    public Person(String lastName, String firstName) {
        this.lastName = lastName;
        this.firstName = firstName;
    }

    public void rename(String firstName, String lastName) throws FailNameException {
        if (firstName == null || lastName == null)
            throw new FailNameException();
        else {
            this.firstName = firstName;
            this.lastName = lastName;
        }
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    @Test
    public static void main(String[] args) {
        Person p = new Person("Gueugnaut", "Andrea");
        // Pass
        Assert.assertNotEquals("Gueugnaut", p.getFirstName());
        // Pass
        Assert.assertEquals("Gueugnaut", p.getLastName());
        // Does not pass
        Assert.assertNotEquals("Andrea", p.getFirstName());
    }
}
