#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/ip.h>

static struct nf_hook_ops nfho;


 /*
 Define the netfilter hook.
 (using the second param (packet stores in that buffer)).
 */
unsigned int hook_func(void *priv, struct sk_buff *skb, const struct nf_hook_state *state) 
{
    struct iphdr *ip_header = (struct iphdr *)skb_network_header(skb); // extract ip from packet
    
    if (ip_header->protocol == IPPROTO_TCP) { // defain uisng TCP protocol
        printk(KERN_INFO "Source IP: %pI4, Destination IP: %pI4\n", // extract source and destionatoin address from the ip
               &ip_header->saddr, &ip_header->daddr);
    }
    
    return NF_ACCEPT;
}


int init_module(void)
{
    nfho.hook = hook_func;
    nfho.hooknum = NF_INET_PRE_ROUTING;
    nfho.pf = PF_INET;
    nfho.priority = NF_IP_PRI_FIRST;
    
    nf_register_net_hook(&init_net, &nfho); // Use init_net as the network structure
    
    return 0;
}

void cleanup_module(void)
{
    nf_unregister_net_hook(&init_net, &nfho); // Use init_net as the network structure
}

MODULE_LICENSE("GPL");
