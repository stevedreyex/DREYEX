import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class mainTest {
  @Test
  public void evaluatesExpression() {
    Tdd a = new Tdd();
    assertEquals(7, a.cal(2,5));
  }
}