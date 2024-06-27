<template>
    <div class="container">
        <div class="card">
            <div class="card-body">
                <slot></slot>
            </div>
        </div>
    </div>

</template>



<script>


export default {
    name: "BaseView",

}
</script>



<style scoped>
.container {
    margin-top: 30px;
}


</style>
