package service;

import dao.FunctionDao;
import domain.Function;
import orm.DaoProxy;

import java.util.ArrayList;

public class FunctionService {
    private FunctionDao dao=(FunctionDao) DaoProxy.getInstance(FunctionDao.class);

    public  ArrayList<Function> getFunctionList(){
        ArrayList<Function> FunctionList=dao.selectList();
        System.out.println("service"+FunctionList);
        return FunctionList;
    }
    public Function getFunction(String Fid ){
         return dao.selectFunctionByFid(Fid);
    }
    public int updateFunction(String Fname,String Fversion,String ProjectName,String ModuleName,String Fpriority,String Fcontent,String Fid){
       return dao.updateFunction(Fname,Fversion,Fpriority,Fcontent,Fid);
    }
    public int insertFunction(String FID,String FunctionName,String Functioncreate,String updateTime,String ModuleMoid,String Functionpriority,String FunctionContent,String fneed,String Functionversion){
        Function function=new Function (Integer.parseInt(FID),FunctionName,Functioncreate,updateTime,Integer.parseInt(ModuleMoid),Integer.parseInt(Functionpriority),FunctionContent,fneed,Functionversion);
        return  dao.insertFunction(function);
    }
    public int deleteFunctionByFid( String Fid){
        return  dao.deleteFunctionByFid(Fid);
    }
    
}
