    #include <linux/fs.h>
    #include <linux/init.h>
    #include <linux/kernel.h>
    #include <linux/sched.h>
    #include <linux/module.h>
    #include <linux/seq_file.h>
    #include <linux/proc_fs.h>
    

    static int meminfo_proc_show(struct seq_file *m, void *v)
    {
		seq_printf(m, "201404034\nManuel Francisco Galván Reyna\nLinux Mint 17\n");

        struct task_struct *task;
        for_each_process(task)
        {
            struct task_struct *task_child;
            struct list_head *list;
                        
            seq_printf(m,"NOMBRE: %s, PID: %d, ESTADO: %li\n", task->comm, task->pid, task->state);

            list_for_each(list,&task->children) {
                task_child=list_entry(list,struct task_struct,sibling);
                 
                seq_printf(m,"\tNOMBRE: %s, PID: %d, ESTADO: %li\n",
                task_child->comm,
				task_child->pid,
				task_child->state);
            }
        }
        return 0;
    }

    static void __exit final(void) //Salida de modulo
    {   
        printk(KERN_INFO "Sistemas Operativos 1\n");
    }

    static int meminfo_proc_open(struct inode *inode, struct file *file)
    {
        return single_open(file, meminfo_proc_show, NULL);
    }

    static const struct file_operations meminfo_proc_fops = {
        .open       = meminfo_proc_open,
        .read       = seq_read,
        .llseek     = seq_lseek,
        .release    = single_release,
    };

    static int __init inicio(void) //Escribe archivo en /proc
    {
		printk(KERN_INFO "201404034\n");
        proc_create("cpu_201404034", 0, NULL, &meminfo_proc_fops);
        return 0;
    }


    module_init(inicio);
    module_exit(final);

MODULE_AUTHOR("Manuel Galván");
MODULE_DESCRIPTION("201404034");
MODULE_LICENSE("GPL");
