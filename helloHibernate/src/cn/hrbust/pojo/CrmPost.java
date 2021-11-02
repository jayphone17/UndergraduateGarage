package cn.hrbust.pojo;

import java.util.HashSet;
import java.util.Set;

public class CrmPost {
  private int postId;
  private CrmDepartment crmDepartment;
  private String name;
  private Set<CrmStaff> crmStaffs = new HashSet<CrmStaff>();

  public int getPostId() {
    return postId;
  }

  public void setPostId(int postId) {
    this.postId = postId;
  }

  public CrmDepartment getCrmDepartment() {
    return crmDepartment;
  }

  public void setCrmDepartment(CrmDepartment crmDepartment) {
    this.crmDepartment = crmDepartment;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public Set<CrmStaff> getCrmStaffs() {
    return crmStaffs;
  }

  public void setCrmStaffs(Set<CrmStaff> crmStaffs) {
    this.crmStaffs = crmStaffs;
  }

  public CrmPost(int postId, CrmDepartment crmDepartment, String name,
                 Set<CrmStaff> crmStaffs) {
    super();
    this.postId = postId;
    this.crmDepartment = crmDepartment;
    this.name = name;
    this.crmStaffs = crmStaffs;
  }
  public CrmPost() {
    super();
  }

  public String toString(){
    return "CrmPost [postID=" + postId + ",name=" + name ;
  }
}
