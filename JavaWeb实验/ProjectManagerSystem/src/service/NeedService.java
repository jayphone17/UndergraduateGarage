package service;

import dao.NeedDao;
import domain.Need;
import orm.DaoProxy;

import java.util.ArrayList;

public class NeedService {
    private static NeedDao dao=(NeedDao) DaoProxy.getInstance(NeedDao.class);


    public Integer editNeedContent(String NeedContent ,String Nid){
       return dao.updateNeedContent( NeedContent , Nid);
    }



    public ArrayList<Need> getNeedListByPjtid(String Pjtid){
        return  dao.selectNeedByPjtid(Pjtid);
    }

    public static ArrayList<String> getNidListbyPjtid(String Pjtid){
        ArrayList <Need> NeedList=dao.selectNeedByPjtid(Pjtid);
        System.out.println("PID"+Pjtid);
        System.out.println("NeedService"+NeedList);
        ArrayList <String> NidList = new ArrayList<>();
        for(int i=0;i<NeedList.size();i++){
            NidList.add(NeedList.get(i).getNid().toString());
        }
        return NidList;
    }
    public static  String getNeedName(Integer  Nid){
        return dao.selectNeedByNid(Nid).getNname();
    }
    public static Need getNeed(Integer  Nid){
        return  dao.selectNeedByNid(Nid);
    }
    public static String getNeedContent(Integer  Nid){
        return dao.selectNeedByNid(Nid).getNcontent();
    }

}
