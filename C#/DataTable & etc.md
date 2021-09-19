## DataRow, DataColumn
레코드와 칼럼을 의미<br>
<br>

## DataTable
DB에서 스키마 만들 듯이 **메모리상에 데이터 테이블을 만들 수 있다.**<br>
<br>

## DataSet
DataSet은 여러개의 DataTable들을 포함하여 마치 **메모리상의 간이 데이타베이스와 같은 개념**으로 이해될 수 있다.<br>
DataSet에 있는 **DataTable을 엑세스하기 위해서는** dataSet.Tables[0]과 같이 **인덱스**를 사용할 수 있으며,<br>
**테이블명**을 이용해서 엑세스할 수도 있다.<br>
<br>

![데이터테이블](https://user-images.githubusercontent.com/43705434/133917466-f9264fd7-0e2f-4430-848e-e1b1e6e06f72.PNG)<br>
<br>


**예제**<br>
```c#
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
 
namespace DataTableTest
{
    public partial class Form1 : Form
    {
        DataSet ds = new DataSet();  // 반의 정보를 가지고 있을 DataSet
 
 
        public Form1()
        {
            InitializeComponent();
        }
 
        /// <summary>
        /// 등록 Button을 Click 했을 경우 반에 대한 DataTable을 만들고 DataTable을 DataSet에 등록
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnReg_Click(object sender, EventArgs e)
        {
            bool bCheckIsTalbe = false;
 
            // DataSet안에 해당하는 DataTable이 있는지 확인 한다
            if (ds.Tables.Contains(cboxRegClass.Text))
            {
                bCheckIsTalbe = true;
            }
 
            //foreach (DataTable oTable in ds.Tables)
            //{
            //    if (oTable.TableName.Contains(cboxRegClass.Text))
            //    {
            //        bCheckIsTalbe = true;
            //        break;
            //    }
            //}
 
            DataTable dt = null;
 
            if (!bCheckIsTalbe)  // 기존 Table이 없을 경우 신규로 생성
            {
                dt = new DataTable(cboxRegClass.Text);
 
                //DataColumn 생성
                DataColumn colName = new DataColumn("NAME", typeof(string));
                DataColumn colSex = new DataColumn("SEX", typeof(string));
                DataColumn colRef = new DataColumn("REF", typeof(string));
 
                //생성된 Column을 DataTable에 Add
                dt.Columns.Add(colName);
                dt.Columns.Add(colSex);
                dt.Columns.Add(colRef);
            }
            else  // 기존 Table이 있을 경우 기존 Table을 가져온다
            {
                dt = ds.Tables[cboxRegClass.Text];
            }
 
 
            //Row 생성
            DataRow row = dt.NewRow();
            row["NAME"] = tboxRegName.Text;
 
            if (rdoRegSexFemale.Checked)
            {
                row["SEX"] = "여자";
            }
            else if (rdoRegSexMale.Checked)
            {
                row["SEX"] = "남자";
            }
 
            row["REF"] = tboxRegRef.Text;
 
 
            //dt.Rows.Add(row);
 
            //ds.Tables.Add(dt);
            //if (bCheckIsTalbe)
            //{
            //    ds.Tables.Remove(cboxRegClass.Text);
            //    ds.Tables.Add(dt);
            //}
 
            //생성된 Row을 DataTable에 Add
            if (bCheckIsTalbe)
            {
                ds.Tables[cboxRegClass.Text].Rows.Add(row);  // DataSet에 해당 DataTalbe이 있을 경우 기존 Table에 Row를 추가한다
            }
            else
            {
                dt.Rows.Add(row);   // 신규로 작성한 DataTable에 Row를 등록 하고, 
                ds.Tables.Add(dt);  // 등록한 DataTable을 DataSet에 추가한다
            }
 
            cboxViewClass_SelectedIndexChanged(this, null);
        }
 
 
        /// <summary>
        /// DataSet에 있는 DataTable을 찾아서 선택한 DataRow를 삭제
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnViewDataDel_Click(object sender, EventArgs e)
        {
            int iSelectRow = dgViewInfo.SelectedRows[0].Index;  // 선택 한 Row 중에서 첫번째 Row번호를 가져온다
            ds.Tables[cboxViewClass.Text].Rows.RemoveAt(iSelectRow);   // Table에서 선택한 Row를 삭제 한다
 
            cboxViewClass_SelectedIndexChanged(this, null);
        }
 
 
        /// <summary>
        /// View 부분의 Combobox의 값을 변경 했을 경우 해당하는 Datagrid를 새로 표시해 주기 위해 사용
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void cboxViewClass_SelectedIndexChanged(object sender, EventArgs e)
        {
            dgViewInfo.DataSource = ds.Tables[cboxViewClass.Text];
 
 
            // DatagridView Cell 정렬 및 Number를 적용
            foreach (DataGridViewRow oRow in dgViewInfo.Rows)
            {
                oRow.HeaderCell.Value = oRow.Index.ToString();
            }
            dgViewInfo.AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode.AutoSizeToAllHeaders);
        }
        
        /// <summary>
        /// 수정
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnModify_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(tboxRegName.Text))
            {
                foreach (DataRow oitem in ds.Tables[cboxRegClass.Text].Rows)
                {
                    if (oitem["NAME"].Equals(tboxRegName.Text))
                    {
                        if (rdoRegSexFemale.Checked)
                        {
                            oitem["SEX"] = "여자";
                        }
                        else if (rdoRegSexMale.Checked)
                        {
                            oitem["SEX"] = "남자";
                        }
 
                        oitem["REF"] = tboxRegRef.Text;
                    }
                }
 
                cboxViewClass_SelectedIndexChanged(this, null);
            }
        }
    }
}
```
<br>
<br>

## 참조링크
https://www.csharpstudy.com/Data/SQL-dataset.aspx <br>
https://cwkcw.tistory.com/122 <br>
