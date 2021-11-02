package com.ascent.action;

import com.ascent.pojo.Expert;
import com.ascent.pojo.ProjectCategory;
import com.ascent.pojo.User;
import com.ascent.service.ExpertService;
import com.ascent.service.ProjectCategoryService;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import java.util.Iterator;
import java.util.Set;
import javax.servlet.http.HttpServletRequest;
import org.apache.struts2.ServletActionContext;

public class ExpertAction extends ActionSupport {
  ProjectCategoryService categoryService;
  Expert expert;
  ExpertService expertService;

  public ExpertAction() {
  }

  public ProjectCategoryService getCategoryService() {
    return this.categoryService;
  }

  public void setCategoryService(ProjectCategoryService categoryService) {
    this.categoryService = categoryService;
  }

  public Expert getExpert() {
    return this.expert;
  }

  public void setExpert(Expert expert) {
    this.expert = expert;
  }

  public ExpertService getExpertService() {
    return this.expertService;
  }

  public void setExpertService(ExpertService expertService) {
    this.expertService = expertService;
  }

  public String displayUpdateExpert() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int expertid = Integer.parseInt(id);
    Expert et = this.expertService.findExpertById(expertid);
    ActionContext context = ActionContext.getContext();
    context.put("expert", et);
    System.out.println(et.getName() + "用户保存成功");
    return "success";
  }

  public String updateExpert() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int expertid = Integer.parseInt(id);
    Expert et = this.expertService.findExpertById(expertid);
    et.setName(this.expert.getName());
    et.setUnitname(this.expert.getUnitname());
    et.setTitle(this.expert.getTitle());
    et.setNation(this.expert.getNation());
    System.out.println(this.expert.getSex());
    et.setSex(this.expert.getSex());
    et.setTel(this.expert.getTel());
    et.setIntroduction(this.expert.getIntroduction());
    this.expertService.updateExpert(et);
    return "success";
  }

  public String deleteExpert() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int expertid = Integer.parseInt(id);
    Expert e = this.expertService.findExpertById(expertid);
    this.expertService.deleteExpert(e);
    return "success";
  }

  public String displayExpertInfo() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int expertid = Integer.parseInt(id);
    Expert expt = this.expertService.findExpertById(expertid);
    ActionContext context = ActionContext.getContext();
    context.put("expert", expt);
    System.out.println(expt.getTel() + expt.getTitle());
    System.out.println("专家对象保存成功！");
    return "success";
  }

  public String updateExpertInfo() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int expertid = Integer.parseInt(id);
    Expert expt = this.expertService.findExpertById(expertid);
    expt.setName(this.expert.getName());
    expt.setUnitname(this.expert.getUnitname());
    expt.setNation(this.expert.getNation());
    expt.setSex(this.expert.getSex());
    expt.setTel(this.expert.getTel());
    expt.setTitle(this.expert.getTitle());
    expt.setIntroduction(this.expert.getIntroduction());
    this.expertService.updateExpert(expt);
    return "success";
  }

  public String updatePassword() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    String password = request.getParameter("password");
    String newpassword = request.getParameter("newpasswrod");
    String newdoublepassword = request.getParameter("newdoublepassword");
    int expertid = Integer.parseInt(id);
    Expert expt = this.expertService.findExpertById(expertid);
    User user = expt.getUser();
    if (user.getPassword().equals(password) && newpassword.equals(newdoublepassword)) {
      user.setPassword(password);
      expt.setUser(user);
      this.expertService.updateExpert(expt);
    }

    return "success";
  }

  public String showProjectCategorys() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int expertid = Integer.parseInt(id);
    Expert expt = this.expertService.findExpertById(expertid);
    Set<ProjectCategory> categorys = expt.getProjectCategories();
    ActionContext context = ActionContext.getContext();
    context.put("categorys", categorys);
    Iterator iterator = categorys.iterator();

    while(iterator.hasNext()) {
      ProjectCategory category = (ProjectCategory)iterator.next();
      System.out.println(category.getCategoryid());
      System.out.println(category.getCategoryname());
      System.out.println(category.getRepStartTime());
      System.out.println(category.getRepStopTime());
    }

    System.out.println("项目类别保存成功!");
    return "success";
  }

  public String findProjectInfo() {
    HttpServletRequest request = ServletActionContext.getRequest();
    String id = request.getParameter("id");
    int categoryid = Integer.parseInt(id);
    Set<ProjectCategory> projects = this.categoryService.findProjectCategoryById(categoryid).getProjects();
    ActionContext context = ActionContext.getContext();
    context.put("projects", projects);
    return "success";
  }
}
