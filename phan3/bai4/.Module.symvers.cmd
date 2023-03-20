cmd_/home/lucy/phan3/bai4/Module.symvers := sed 's/\.ko$$/\.o/' /home/lucy/phan3/bai4/modules.order | scripts/mod/modpost -m -a  -o /home/lucy/phan3/bai4/Module.symvers -e -i Module.symvers   -T -
