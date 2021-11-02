package service;

import dao.ProjectDao;
import domain.Project;
import orm.DaoProxy;

import java.util.ArrayList;

public class ProjectService {
    private static  ProjectDao dao=(ProjectDao) DaoProxy.getInstance(ProjectDao.class);

    public static String getProjectNameByPjtid(Integer Pjtid){
            return  dao.selectProjectByPjtid(Pjtid).getPjtname();
    }

    public ArrayList<String>getProjectNameList(){
        ArrayList<String> projectNameList=new ArrayList<>();
        ArrayList<Project> projectList= dao.selectProjectList();
        for(int i=0;i<projectList.size();i++){
            projectNameList.add(projectList.get(i).getPjtname());
        }
        return projectNameList;
    }
    public static ArrayList<Project>getProjectList(){
        return dao.selectProjectList();
    }
}
