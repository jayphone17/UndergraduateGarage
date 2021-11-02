package service;

import dao.ModuleDao;
import orm.DaoProxy;
import domain.Module;

import java.util.ArrayList;

public class ModuleService {

    private static ModuleDao dao=(ModuleDao) DaoProxy.getInstance(ModuleDao.class);
    public static String getModuleName(Integer  Moid){
            return dao.selectModuleByMoid(Moid).getModuleName()  ;
    }

    public static String getNeedName(Integer Moid){
        //通过Moid 主键 得到这个表里的外键Nid
        //再把Nid放到NeedService 里来得到Nid对应的对象的NeedName；
        return NeedService.getNeedName(dao.selectModuleByMoid(Moid).getNid());
    }
    public static String getNeedContent(Integer Moid){
        //得到需求内容
        return NeedService.getNeedContent(dao.selectModuleByMoid(Moid).getNid());
    }
    public static String getNeedNid(Integer Moid){
        return dao.selectModuleByMoid(Moid).getNid().toString();
    }


    public static String getProjectName(Integer Moid){
       //传进来的是nid
       return ProjectService.getProjectNameByPjtid(NeedService.getNeed(dao.selectModuleByMoid(Moid).getNid()).getPjtid());
    }
    public static  String getProjectId(Integer Moid){
        return NeedService.getNeed(dao.selectModuleByMoid(Moid).getNid()).getPjtid().toString();
    }
    public ArrayList<Module> getModuleListbyPjtid(String Pjtid){
        System.out.println("service执行了");
        ArrayList<String> NidList=null;
        ArrayList<Module> ModuleList= new ArrayList<>();
        NidList = NeedService.getNidListbyPjtid(Pjtid);
        System.out.println(NidList+"------>>>>");
       for(int i=0;i<NidList.size();i++){
           Module m = dao.selectMoudleByNid(NidList.get(i));
           ModuleList.add(m);
       }
       return ModuleList;
    }
    public ArrayList<Module> getModuleList(){
        return dao.selectList();
    }
    public Module getModulebyMoid(Integer Moid){
        return dao.selectModuleByMoid(Moid);
    }

    public Integer updateModule(String Moname,String Monick,String Moupdate,String Nid,String Mopriority,String Mocontent,String Moneed,String Moid){
       return dao.updateModule(Moname,Monick,Moupdate,Nid,Mopriority,Mocontent,Moneed,Moid);

    }
    public Integer updateMoneed(String Moneed,String Moid){

        return dao.updateMoneed(Moneed,Moid);
    }
    public Integer InsertModule(Module module){
        return  dao.insertModule(module);
    }
    public Integer deleteModuleByMoid(String Moid){
        return  dao.deleteModuleByMoid(Moid);
    }

}
