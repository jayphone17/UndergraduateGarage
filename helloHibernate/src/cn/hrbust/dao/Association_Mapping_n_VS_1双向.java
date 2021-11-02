package cn.hrbust.dao;
import cn.hrbust.pojo.Group;
import cn.hrbust.pojo.User;
import junit.framework.TestCase;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import java.lang.module.Configuration;
import java.sql.Date;

public class Association_Mapping_n_VS_1双向 extends TestCase {
  //保存瞬时对象
  public void testSaveUserAndGroup(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    Group g = new Group();
    g.setName("软件工程");
    User u = new User();
    u.setName("王五");
    u.setGender("男");
    u.setAge(33);
    u.setBirthday(Date.valueOf("2001-1-1"));
    u.setName("赵六");
    u.setGroup(g);
    User u1 = new User();
    u1.setName("林七");
    u1.setGender("女");
    u1.setAge(25);
    u1.setBirthday(Date.valueOf("1996-1-1"));
    u1.setName("lueluelue");
    u1.setGroup(g);
    g.getUsers().add(u);
    g.getUsers().add(u1);
    try {
      sf = HibernateUtil.getSf(); //sessionfactory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      session.save(g);
      session.save(u);
      ts.commit();
      u.setName("王五");  //事务提交后，Session关闭，属性改变，此时的对象的属性变化不会发送update语句
    } catch (HibernateException e) {
      e.printStackTrace();
      if(ts != null){
        ts.rollback();
      }
    }finally{
      //session.close();
      //sf.close();
    }
  }
}
