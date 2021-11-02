package hao.listener;
import javax.servlet.annotation.WebListener;
import javax.servlet.http.HttpSessionAttributeListener;
import javax.servlet.http.HttpSessionBindingEvent;
@WebListener
public class UserCounterListener implements HttpSessionAttributeListener {
    public UserCounterListener() {
    }
    public void attributeAdded(HttpSessionBindingEvent se)  { 
    	Object obj = se.getSession().getServletContext().getAttribute("OnlineCounter");
    	int counter = 0;
    	if(obj!=null)
    		counter = (int) obj;
    	if(se.getName()=="student")
    		counter++;
    	se.getSession().getServletContext().setAttribute("OnlineCounter", counter);	
    }
    public void attributeRemoved(HttpSessionBindingEvent se)  { 
    	int counter = (int) se.getSession().getServletContext().getAttribute("OnlineCounter");
    	if(se.getName()=="student")
    		counter--;
    	se.getSession().getServletContext().setAttribute("OnlineCounter", counter);
    }
    public void attributeReplaced(HttpSessionBindingEvent se)  { 
    }	
}
