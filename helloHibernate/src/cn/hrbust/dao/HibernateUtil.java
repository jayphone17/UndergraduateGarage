package cn.hrbust.dao;

import org.hibernate.HibernateException;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

public class HibernateUtil {
  //使用静态方法实现一个单例模式：
  private static SessionFactory sf= null;
  private static Configuration cfg = null;
  static { //在类加载的时候只能执行一次
    try {
      cfg = new Configuration().configure();
      sf  = cfg.buildSessionFactory();
    }catch(HibernateException he){
      he.printStackTrace();
    }
  }
  public static SessionFactory getSf(){
    return sf;
  }
  public static void closeSessionFactory(){
    sf.close();
  }

  //使用DLC创建一个单例模式：
//  private volatile static SessionFactory sf = null;
//  private volatile static Configuration cfg = null;
//  private SessionFactory(){}
//  private Configuration(){}
//
//  public static SessionFactory getSf(){
//    if(sf!=null){
//      synchronized (SessionFactory.class){
//        if(sf==null){
//          sf = new SessionFactory();
//        }
//      }
//    }
//    return sf;
//  }
//
//  public static Configuration getCfg(){
//    if(cfg!=null){
//      synchronized (Configuration.class){
//        if(cfg==null){
//          cfg = new Configuration();
//        }
//      }
//    }
//    return cfg;
//  }

}
